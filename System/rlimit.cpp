/*
 * rlimit.cpp
 *
 *  Created on: Jun 28, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"
#include <sys/resource.h>

void coredump_test()
{
    struct rlimit lm;
    int ret = getrlimit(RLIMIT_CORE, &lm);

    if(ret == -1)
    {
        Log("getrlimit(RLIMIT_CORE) failed");
        return;
    }
    Log("%lu, %lu", lm.rlim_cur, lm.rlim_max);

    struct rlimit slm;
    slm.rlim_cur = RLIM_INFINITY;
    slm.rlim_max = RLIM_INFINITY;

    ret = setrlimit(RLIMIT_CORE, &slm);
    if(ret == -1)
    {
        Log("setrlimit(RLIMIT_CORE) failed, errno:%d", errno);
        return;
    }

    ret = getrlimit(RLIMIT_CORE, &lm);
    if(ret == -1)
    {
        Log("getrlimit(RLIMIT_CORE) 2 failed");
        return;
    }
    Log("%lu, %lu", lm.rlim_cur, lm.rlim_max);
}

void resource_limit_test()
{
    coredump_test();
}




