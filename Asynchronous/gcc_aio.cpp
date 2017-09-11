/*
 * gcc_aio.cpp
 *
 *  Created on: Jun 21, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

#include <fcntl.h>
#include <aio.h>

#include <signal.h>

#include <errno.h>

void aio_completion_handler(int signo, siginfo_t* info, void *context)
{
    if(!info)
    {
        return;
    }

    if(info->si_signo != SIGIO)
    {
        return;
    }

//    struct aiocb* req;

//    req = (struct aiocb*)info->si_
}

void aio_read_file()
{
    const int DATA_SIZE = 128;

    int fd = open("/home/ruanbo/Codes/CppTest/Asynchronous/aio_test.txt", O_RDWR);
    if(fd == -1)
    {
        Log("open file failed");
        return;
    }

    struct aiocb cb;
    bzero(&cb, sizeof(aiocb));
    cb.aio_buf = malloc(DATA_SIZE);
    if(!cb.aio_buf)
    {
        Log("malloc failed");
        close(fd);
        return;
    }

    cb.aio_fildes = fd;
    cb.aio_nbytes = DATA_SIZE;
    cb.aio_offset = 0;

    int ret = aio_read(&cb);
    if(ret == -1)
    {
        Log("aio_read failed");
        close(fd);
        return;
    }

    while(aio_error(&cb) == EINPROGRESS)
    {
        ret = aio_return(&cb);
        if(ret > 0)
        {

        }
        else
        {
            Log("aio_return failed");
        }
    }

    close(fd);
}














