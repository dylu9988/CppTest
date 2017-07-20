/*
 * raw_socket.cpp
 *
 *  Created on: Jun 24, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <errno.h>

void show_ip(const iphdr* ip)
{
    Log("========= ip header =======");

//    Log("tos:%u", ip->tos);
    Log("protocol:%u", ip->protocol);
    Log("header len:%u bytes", ip->ihl * 4);
    Log("total len:%x", ip->tot_len);
    Log("src ddr:%s", inet_ntoa(*(struct in_addr*)&ip->saddr));
    Log("des ddr:%s", inet_ntoa(*(struct in_addr*)&ip->daddr));

    Log("======== ip header end ====\n");
}

void show_tcp(const tcphdr* tcp)
{
    Log("======= tcp header ========");

    Log("src port:%u", tcp->source);
    Log("dst port:%u", tcp->dest);
    Log("header len:%u bytes", tcp->doff * 4);

    Log("====== tcp header end =====")
}


void raw_socket_test()
{
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if(sock == -1)
    {
        Log("socket() failed, errno:%d", errno);
        return;
    }

    struct iphdr iph;

    char rbuff[40960] = { 0 };
    unsigned int data_len = 0;
    while(true)
    {
        int rsize = recv(sock, rbuff, 256, 0);
        if(rsize == -1)
        {
            Log("recv failed");
            break;
        }

        data_len += rsize;



        if(data_len > sizeof(iph))
        {
            break;
        }



    }
    if(data_len > sizeof(iph))
    {
        struct iphdr* pih = (iphdr*)rbuff;
        show_ip(pih);

        if(data_len > pih->tot_len)
        {

        }
    }


}












