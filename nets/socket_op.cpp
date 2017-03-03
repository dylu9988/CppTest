/*
 * socket_op.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

#include <net/if.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#include <sys/resource.h>


void rlimit_set_maxfilesize()
{
    int ret = 0;

    {
        struct rlimit limit;
        ret = getrlimit(RLIMIT_NOFILE, &limit);
        if(ret != 0)
        {
            Log("getrlimit Error");
            return;
        }

        Log("getrlimit RLIMIT_NOFILE cur:%ld, max:%ld", limit.rlim_cur, limit.rlim_max);
    }

    {
        struct rlimit stack_limit;
        stack_limit.rlim_cur = 1024;
        stack_limit.rlim_max = 1024;

        if(setrlimit(RLIMIT_NOFILE, &stack_limit) != 0)
        {
            Log("setrlimit Error");
            return;
        }
    }

    {
        struct rlimit limit;
        ret = getrlimit(RLIMIT_NOFILE, &limit);
        if(ret != 0)
        {
            Log("getrlimit Error");
            return;
        }

        Log("getrlimit RLIMIT_NOFILE 2 cur:%ld, max:%ld", limit.rlim_cur, limit.rlim_max);
    }

}

void max_file_num()
{
    rlimit_set_maxfilesize();

    list<int> socks;

    while(true)
    {
        int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(sock_fd == -1)
        {
            break;
        }

        socks.push_back(-1);
    }


    Log("socks num:%ld", socks.size());

    for(list<int>::const_iterator it=socks.begin(); it!=socks.end();++it)
    {
        close(*it);
    }

}

void socket_buff_size()
{
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock == -1)
    {
        Log("socket() Error:%d", errno);
        return;
    }

}



void socket_op_test()
{
    max_file_num();

}


