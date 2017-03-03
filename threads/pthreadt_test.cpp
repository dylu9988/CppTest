/*
 * pthreadt_test.cpp
 *
 *  Created on: Feb 25, 2017
 *      Author: ruanbo
 */


#include <pthread.h>

#include "comm/comm.hpp"

class CThreadParam
{
public:
    pthread_t _pid;
public:
    CThreadParam()
    {
        _pid = 0;
    }

public:
    void show()
    {
        Log("show");
    }
};


static void* thread_start(void *arg)
{
    CThreadParam* param = (CThreadParam*)arg;
    if(!param)
    {
        Log("pthread parameter error");
        return NULL;
    }

    Log("thread_start, pid:%lu", param->_pid);
    param->show();

    if(true)
    {
        pthread_attr_t attr;
        int ret = pthread_attr_init(&attr);
//        int ret = pthread_getattr_np(pthread_self(), &attr);
        if(ret != 0)
        {
            Log("pthread_getattr_np failed");
        }

        size_t stack_size = 2 * 1024 * 1024;
        ret = pthread_attr_setstacksize(&attr, stack_size);
        if(ret != 0)
        {
            Log("pthread_attr_setstacksize failed");
        }

    }

    {
        pthread_attr_t attr;
        pthread_attr_init(&attr);

        size_t stack_size = 0;
        int ret = pthread_attr_getstacksize(&attr, &stack_size);
        if(ret != 0)
        {
            Log("pthread_attr_getstacksize Error");
            return NULL;
        }
        else
        {
            Log("stack_size:%ldB, %ldK, %ldM", stack_size, stack_size/1024, stack_size/1024/1024);
        }

    }

    sleep(3);

    Log("thread_start end");

    return NULL;
}


void pthread_tests()
{
    pthread_attr_t attr;
//    int ret = pthread_getattr_np(pthread_self(), &attr);
    int ret = pthread_attr_init(&attr);
    if(ret != 0)
    {
        Log("pthread_getattr_np failed");
    }

//    size_t stack_size = 2 * 1024 * 1024;
//    ret = pthread_attr_setstacksize(&attr, stack_size);
//    if(ret != 0)
//    {
//        Log("pthread_attr_setstacksize failed");
//    }

    Log("main thread id:%lu", pthread_self());

    CThreadParam* arg = new CThreadParam();
    arg->_pid = 100;

    pthread_t pid = 0;
    ret = pthread_create(&pid, &attr, thread_start, arg);
    if(ret != 0)
    {
        Log("pthread_create failed");
        return;
    }
    else
    {
        Log("pthread_create ok.pid=%lu", pid);
    }



    Log("after pthread_create")

    pthread_join(pid, NULL);

    delete arg;
}



