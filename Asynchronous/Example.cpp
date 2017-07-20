/*
 * Example.cpp
 *
 *  Created on: Jun 21, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

#include <fcntl.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <libaio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

//#include <linux/aio_abi.h>

//DEFINE_int32(file_size, 10, "Length of file in 4k blocks");
//DEFINE_int32(concurrent_requests, 100, "Number of concurrent requests");
//DEFINE_int32(min_nr, 1, "min_nr");
//DEFINE_int32(max_nr, 1, "max_nr");

string FilePath = "/home/ruanbo/Codes/CppTest/Asynchronous/aio_file.txt";
int file_size = 10;
int concurrent_requests = 100;
int min_mr = 1;
int max_nr = 1;

#define LogRed(...) {printf("\033[47;31m%s\033[0m\n", __VA_ARGS__);}

// The size of operation that will occur on the device
static const int nPageSize = 4096;

class AIORequest
{
public:
    int* _buffer;

    virtual void Complete(int res) = 0;

    AIORequest()
    {
        int ret = posix_memalign(reinterpret_cast<void**>(&_buffer), nPageSize,
                nPageSize);
        CHECK_EQ(ret, 0);
    }

    virtual ~AIORequest()
    {
        free(_buffer);
    }
};

class Adder
{
public:
    virtual void Add(int amount) = 0;

    virtual ~Adder()
    {
    }
    ;
};

class AIOReadRequest: public AIORequest
{
private:
    Adder* adder_;

public:
    AIOReadRequest(Adder* adder) :
            AIORequest(), adder_(adder)
    {
    }

    virtual void Complete(int res)
    {
        CHECK_EQ(res, nPageSize)<< "Read incomplete or error " << res;
        int value = _buffer[0];

        LOG(INFO) << "Read of " << value << " completed";

        adder_->Add(value);
    }
};

class AIOWriteRequest: public AIORequest
{
private:
    int _value;

public:
    AIOWriteRequest(int value) :
            AIORequest(), _value(value)
    {
        _buffer[0] = value;
    }

    virtual void Complete(int res)
    {
        CHECK_EQ(res, nPageSize)<< "Write incomplete or error " << res;

        LOG(INFO) << "Write of " << _value << " completed";
    }
};

class AIOAdder: public Adder
{
private:
    int _fd;
    io_context_t _ioctx;
    int _counter;
    int _reap_counter;
    int _sum;
    int _length;

public:
    AIOAdder(int length) :
            _ioctx(0), _counter(0), _reap_counter(0), _sum(0), _length(length)
    {
    }

    ~AIOAdder()
    {
        LOG(INFO) << "Closing AIO context and file";
        io_destroy(_ioctx);
        close(_fd);
    }

public:
    bool Init()
    {
        Log("open file:%s", FilePath.c_str());
        _fd = open(FilePath.c_str(), O_RDWR | O_DIRECT | O_CREAT, 0644);
        if(_fd == -1)
        {
            LogError("open file failed");
            return false;
        }
        if(fallocate(_fd, 0, 0, nPageSize * _length) == -1)
        {
            LogError("fallocate file failed");
            close(_fd);
            return false;
        }

        if(io_setup(100, &_ioctx) == -1)
        {
            LogError("io_setup failed");
            close(_fd);
            return false;
        }

        return true;
    }

    virtual void Add(int amount)
    {
        _sum += amount;
        LOG(INFO) << "Adding " << amount << " for a total of " << _sum;
    }

    void SubmitWrite()
    {
        LOG(INFO) << "Submitting a write to " << _counter;
        struct iocb iocb;
        struct iocb* iocbs = &iocb;
        AIORequest *req = new AIOWriteRequest(_counter);
        io_prep_pwrite(&iocb, _fd, req->_buffer, nPageSize, _counter * nPageSize);
        iocb.data = req;
        int res = io_submit(_ioctx, 1, &iocbs);
        if(res != 1)
        {
            Log("[%s]io_submit failed", __FUNCTION__);
        }
//        CHECK_EQ(res, 1);
    }

    void WriteFile()
    {
        _reap_counter = 0;
        for (_counter = 0; _counter < _length; _counter++)
        {
            SubmitWrite();
            Reap();
        }
        ReapRemaining();
    }

    void SubmitRead()
    {
        LOG(INFO) << "Submitting a read from " << _counter;

        struct iocb iocb;
        struct iocb* iocbs = &iocb;
        AIORequest *req = new AIOReadRequest(this);
        io_prep_pread(&iocb, _fd, req->_buffer, nPageSize, _counter * nPageSize);
        iocb.data = req;
        int res = io_submit(_ioctx, 1, &iocbs);
        if(res != 1)
        {
            Log("[%s]io_submit failed", __FUNCTION__);
        }
//        CHECK_EQ(res, 1);
    }

    void ReadFile()
    {
        _reap_counter = 0;
        for (_counter = 0; _counter < _length; _counter++)
        {
            SubmitRead();
            Reap();
        }
        ReapRemaining();
    }

    int DoReap(int minnr)
    {
//        LOG(INFO) << "Reaping between " << minnr << " and "
//        << max_nr << " io_events";

        struct io_event* events = new io_event[max_nr];
        struct timespec timeout;
        timeout.tv_sec = 0;
        timeout.tv_nsec = 100000000;
        int event_num;

//        LOG(INFO) << "Calling io_getevents";

        event_num = io_getevents(_ioctx, minnr, max_nr, events,
                &timeout);

//        LOG(INFO) << "Calling completion function on results";

        Log("Calling io_getevents & Calling completion function on results");

        for (int i = 0; i < event_num; i++)
        {
            struct io_event event = events[i];
            AIORequest* req = static_cast<AIORequest*>(event.data);
            req->Complete(event.res);
            delete req;
        }
        delete events;

        LOG(INFO) << "Reaped " << event_num << " io_events";

        _reap_counter += event_num;
        return event_num;
    }

    void Reap()
    {
        if (_counter >= min_mr)
        {
            DoReap(min_mr);
        }
    }

    void ReapRemaining()
    {
        while (_reap_counter < _length)
        {
            DoReap(1);
        }
    }



    int Sum()
    {
        LOG(INFO) << "Writing consecutive integers to file";
        WriteFile();

        LOG(INFO) << "Reading consecutive integers from file";
        ReadFile();

        return _sum;
    }
};

void example_run()
{
    //google::ParseCommandLineFlags(&argc, &argv, true);

    AIOAdder adder(file_size);
    if(adder.Init() == false)
    {
        return;
    }

    int sum = adder.Sum();

    int expected = (file_size * (file_size - 1)) / 2;

    LOG(INFO)<< "AIO is complete";

    CHECK_EQ(sum, expected)<< "Expected " << expected << " Got " << sum;

    printf("Successfully calculated that the sum of integers from 0"
            " to %d is %d\n", file_size - 1, sum);
}

