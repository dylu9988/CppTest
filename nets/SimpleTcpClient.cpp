
#include <sys/ioctl.h>
#include <netinet/if_ether.h> // arpreq
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>  // addrinfo
#include <fcntl.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <string.h>   //bzero()
#include <unistd.h>   // close()
#include <errno.h>
#include <sys/epoll.h>   //epoll

#include <stdio.h>
#include <stdarg.h>
#include <string>

using namespace std;

#define LogErr(...) {printf(__VA_ARGS__); printf("\n"); }

#define EP_EVENT_SIZE  256
#define ENOUGH_BUFFER_SIZE 1024



void tcp_client()
{
    int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock_fd < 0)
    {
        LogErr("socket() failed");
        return;
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr)); // 初始化服务器地址
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(20480);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    int ret = connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));      // 主动连接服务器
    if(ret == -1)
    {
        LogErr("connect failed. errno:%d", errno);
        close(sock_fd);
        return;
    }

    string msg = "This is a tcp client";
    int w_ret = ::write(sock_fd, msg.data(), msg.length());
    if(w_ret > 0)
    {
        LogErr("write ok");
    }

    sleep(30);

    close(sock_fd);
}


void upd_client()
{
    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock_fd < 0)
    {
        LogErr("socket() failed");
        return;
    }

    struct sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr)); // 初始化服务器地址
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(10240);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    string msg = "This is a upd client";
    int w_ret = sendto(sock_fd, msg.data(), msg.length(), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(w_ret > 0)
    {
        LogErr("write ok");
    }

    close(sock_fd);
}

void client_test()
{
    tcp_client();

//    upd_client();
}






