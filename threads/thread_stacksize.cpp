/*
 * thread_stacksize.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

#include <pthread.h>
#include <sys/resource.h>

void change_thread_stacksize()
{
    size_t stack_size = 1024 * 1024;  // 1M

    pthread_attr_t attr;
    int ret = pthread_attr_init(&attr);
    if(ret != 0)
    {
        Log("pthread_atr_init Error:%d", ret);
    }

//    ret = pthread_attr_setstacksize(&attr, stack_size);
//    if(ret != 0)
//    {
//        Log("pthread_attr_setstacksize Error:%d", ret);
//    }

//    ret = pthread_attr_init(&attr);
//    if(ret != 0)
//    {
//        Log("pthread_attr_init 2 Error:%d", ret);
//        return;
//    }

    stack_size = 0;
    ret = pthread_attr_getstacksize(&attr, &stack_size);

    if(ret != 0)
    {
        Log("pthread_attr_getstacksize 2 Error");
        return;
    }

    Log("thread stack size after set:%ld", stack_size);
}

void rlimit_set_stacksize()
{
    int ret = 0;

    {
        struct rlimit limit;
        ret = getrlimit(RLIMIT_STACK, &limit);
        if(ret != 0)
        {
            Log("getrlimit Error");
            return;
        }

        Log("getrlimit RLIMIT_STACK cur:%ld, max:%ld", limit.rlim_cur, limit.rlim_max);
    }

    {
        struct rlimit stack_limit;
        stack_limit.rlim_cur = 1024 * 1024;
        stack_limit.rlim_max = 1024 * 1024;

        if(setrlimit(RLIMIT_STACK, &stack_limit) != 0)
        {
            Log("setrlimit Error");
            return;
        }
    }

    {
        struct rlimit limit;
        ret = getrlimit(RLIMIT_STACK, &limit);
        if(ret != 0)
        {
            Log("getrlimit Error");
            return;
        }

        Log("getrlimit RLIMIT_STACK 2 cur:%ld, max:%ld", limit.rlim_cur, limit.rlim_max);
    }

}

static void* thread_funcs(void* arg)
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

    Log("stack_size:%ldB, %ldK", stack_size, stack_size/1024);

    for(int i=0; i<5; ++i)
    {
        Log("thread func");
        sleep(1);
    }

    return NULL;
}

void thread_stacksize_test()
{
//    change_thread_stacksize();

    rlimit_set_stacksize();

    pthread_t pid = 0;
    int ret = pthread_create(&pid, NULL, thread_funcs, NULL);
    if(ret != 0)
    {
        Log("pthread_create Error");
        return;
    }

    pthread_join(pid, NULL);
}


