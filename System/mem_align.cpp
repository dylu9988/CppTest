/*
 * mem_align.cpp
 *
 *  Created on: Jun 21, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

#include <sys/stat.h>

void memalign_test()
{
    char* buff = NULL;

    struct stat st;
    stat("/", &st);

    Log("block size:%ld", st.st_blksize);

    int ret = posix_memalign((void**)&buff, st.st_blksize, 64);
    if(ret == -1)
    {
        Log("posix_memalign() failed");
        return;
    }
    else
    {
        Log("ret:%d", ret);
    }

    Log("sizeof(buff):%ld", sizeof(buff));
    Log("strlen(buff):%ld", strlen(buff));

    if(buff)
    {
        delete buff;
    }
}




