/*
 * Getaddrinfo.cpp
 *
 *  Created on: Jul 20, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

#include <netdb.h>

void getaddrinfo_test1()
{
    struct addrinfo hints, *servinfo, *p;

    memset(&hints,0,sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;    /* No effect if bindaddr != NULL */

    int port = 10240;
    char _port[6];  /* strlen("65535") */
    snprintf(_port,6,"%d",port);

    int ret = getaddrinfo(NULL,_port,&hints,&servinfo);

    if(ret != 0)
    {
        Log("getaddrinfo failed");
        return;
    }

    for (p = servinfo; p != NULL; p = p->ai_next)
    {
        // AF_INIT:2, SOCK_STREAM:1, IPPROTO_TCP:6
        Log("family:%d, socktype:%d, protocol:%d", p->ai_family, p->ai_socktype, p->ai_protocol)
    }

    freeaddrinfo(servinfo);
}





void getaddrinfo_test()
{
    getaddrinfo_test1();
}



