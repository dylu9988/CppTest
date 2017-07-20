/*
 * native_aio.cpp
 *
 *  Created on: Jun 21, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

#include <libaio.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/stat.h>

#define TEST_AIO_MAXIO 32
#define TEST_RDWR_SIZE 256

#define TEST_READ_SIZE 4
#define TEST_READ_CNT 2

int read_cnt = 0;

void rd_done(io_context_t ctx, struct iocb* cb, long res, long res2)
{
    int iosize = cb->u.c.nbytes;
    char* buf = (char*) cb->u.c.buf;
    off_t offset = cb->u.c.offset;

    if (false)
    {
        if (res2 != 0)
        {
            Log("aio read");
        }

        if (res != iosize)
        {
            Log("read size not ok. except:%d, got:%ld, errno:%d", iosize, res2,
                    errno);
            //return;
        }
    }

    if (true)
    {
        Log("aio read done event.res:%ld, res2:%ld, nbytes:%d, offset:%ld", res,
                res2, iosize, offset);
    }

    Log("read[%d]:%s, strlen(buf):%lu, buf:%p", ++read_cnt, buf, strlen(buf), buf);
}

void aio_file()
{
    string file = "/home/ruanbo/Codes/CppTest/Asynchronous/aio_test.txt";
    io_context_t ctx;
    bzero(&ctx, sizeof(ctx));
    io_queue_init(TEST_AIO_MAXIO, &ctx);

    struct stat blk_info;
    stat("/", &blk_info);
    long int blksize = blk_info.st_blksize;
    Log("block size:%ld", blksize);

    if (io_setup(10, &ctx) == -1)
    {
        Log("io_setup failed");
        return;
    }

    int fd = open(file.data(), O_RDWR);
    if (fd == -1)
    {
        Log("open failed");
        io_destroy(ctx);
        return;
    }

    char* buff = NULL;
    char* buff2 = NULL;

    int ret = posix_memalign((void**) &buff, blksize, TEST_RDWR_SIZE);
    if (ret < 0)
    {
        Log("posix_memalign() failed");
        return;
    }
    else
    {
        Log("posix_memalign buff ret:%d, buff:%p", ret, buff);
    }

    ret = posix_memalign((void**) &buff2, blksize, TEST_RDWR_SIZE);
    if (ret < 0)
    {
        Log("posix_memalign() failed");
        return;
    }
    else
    {
        Log("posix_memlign buff2 ret:%d, buff2:%p", ret, buff2);
    }

    Log("delete file now");
    sleep(30);
    Log("start io_submit");

    struct iocb io[TEST_READ_CNT];

    {
        io_prep_pread(&io[0], fd, (void*) buff, TEST_READ_SIZE, 0);
        io_set_callback(&io[0], rd_done);

        struct iocb* pio = &io[0];
        ret = io_submit(ctx, 1, &pio);
        if (ret == -1)
        {
            Log("io_submit() failed");
            io_destroy(ctx);
            close(fd);
            return;
        }
    }

    {
        io_prep_pread(&io[1], fd, (void*) buff2, TEST_READ_SIZE,
                TEST_READ_SIZE);
        io_set_callback(&io[1], rd_done);

        struct iocb* pio = &io[1];
        ret = io_submit(ctx, 1, &pio);
        if (ret == -1)
        {
            Log("io_submit() failed");
            io_destroy(ctx);
            close(fd);
            return;
        }
    }

    struct io_event events[TEST_AIO_MAXIO];
    io_callback_t cb;

    int event_num = 0;
    while (event_num < TEST_READ_CNT)
    {
        int num = io_getevents(ctx, 1, TEST_AIO_MAXIO, events, NULL);

        for (int i = 0; i < num; i++)
        {
            cb = (io_callback_t) events[i].data;

            struct iocb *io = events[i].obj;

            cb(ctx, io, events[i].res, events[i].res2);
        }

        event_num += num;
    }

    sleep(3);

    io_destroy(ctx);
    close(fd);
}

void native_aio_test()
{
    aio_file();
}

