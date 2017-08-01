/*
 * thread_cond.cpp
 *
 *  Created on: Jan 4, 2016
 *      Author: ruanbo
 */


#include <comm/Log.hpp>
#include <stdlib.h>
#include <pthread.h>
#include <vector>
#include <unistd.h>

//#include <thread>



class ThreadData
{
public:
    bool _signal;
    std::vector<int> _data;
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;

    bool _quit;

    long int _c_cnt;
    long int _c_time;

    long int _p_cnt;
    long int _p_time;

public:
    ThreadData()
    {
        _signal = false;
        _c_cnt = 0;
        _c_time = 0;
        _p_cnt = 0;
        _p_time = 0;

        _quit = false;

        _data.clear();

        pthread_mutex_init(&_mutex, NULL);
        pthread_cond_init(&_cond, NULL);
    }

    ~ThreadData()
    {
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_cond);
    }


    void get_data(std::vector<int>& ret)
    {
        _data.swap(ret);
    }

    void add_data(int data)
    {
        _data.push_back(data);
    }

};


static void *pthread_consumer(void *thread_data)
{
    ThreadData *data = (ThreadData*)thread_data;
    bool is_quit = false;
    std::vector<int> ops;

    while(true)
    {
        ops.clear();

        pthread_mutex_lock(&data->_mutex);

        while(!data->_signal)
        {
            pthread_cond_wait(&data->_cond, &data->_mutex);
        }
        data->_signal = false;

        data->get_data(ops);
        for(auto &i : ops)
        {
            data->_c_cnt += i;
        }
        data->_c_time++;
        is_quit = data->_quit;

        pthread_mutex_unlock(&data->_mutex);

        if(is_quit)
        {
            break;
        }
    }

    return NULL;
}

static void *pthread_producer(void *thread_data)
{
    ThreadData *data = (ThreadData*)thread_data;
    bool is_quit = false;

    while(true)
    {
        long int num = random() % 10 + 1;

        pthread_mutex_lock(&data->_mutex);
        data->add_data(num);
        data->_p_cnt += num;
        data->_p_time++;
        data->_signal = true;
        is_quit = data->_quit;
        pthread_cond_signal(&data->_cond);
        pthread_mutex_unlock(&data->_mutex);

        if(is_quit)
        {
            break;
        }

        usleep(1);
    }

    return NULL;
}

void thread_cond_test()
{
    pthread_t pid_c = 0;
    pthread_t pid_p = 0;

    ThreadData *td = new ThreadData();

    int ret = pthread_create(&pid_c, NULL, pthread_consumer, (void*)td);
    if(ret != 0)
    {
        Log("pthread_create 1 error");
        return;
    }
    ret = pthread_create(&pid_p, NULL, pthread_producer, (void*)td);
    if(ret != 0)
    {
        Log("pthread_create 2 error");
        return;
    }

    int run_seconds = 0;
    while(true)
    {
        run_seconds++;
        sleep(1);
        if(run_seconds >= 300)
        {
            break;
        }
        LogLine("%d ", run_seconds);
    }
    Log("\nstatistics:");

    {
        pthread_mutex_lock(&td->_mutex);
        td->_quit = true;
        pthread_mutex_unlock(&td->_mutex);
    }

    ret = pthread_join(pid_c, NULL);
    if(ret != 0)
    {
        Log("pthread_join 1 error");
        return;
    }
    ret = pthread_join(pid_p, NULL);
    if(ret != 0)
    {
        Log("pthread_join 2 error");
        return;
    }

    Log("consumer - cnt:%ld, times:%ld", td->_c_cnt, td->_c_time);
    Log("productor - cnt:%ld, times:%ld", td->_p_cnt, td->_p_time);

    Log("=== end of thread_cond ===");
}






