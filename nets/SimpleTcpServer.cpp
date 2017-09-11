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
#include <fstream>

using namespace std;

#define LogErr(...) {printf(__VA_ARGS__); printf("\n"); }

#define EP_EVENT_SIZE  256
#define ENOUGH_BUFFER_SIZE 1024

bool set_options(int fd)
{
    int flags = ::fcntl(fd, F_GETFL, 0);
    if(flags == -1)
    {
        return false;
    }

    flags = flags | O_NONBLOCK;
    int ret = fcntl(fd, F_SETFL, flags);
    if(ret == -1)
    {
        return false;
    }

    return true;
}

bool epoll_add_sock(int epoll_fd, int sock_fd)
{
    struct epoll_event ee = { 0, { 0 } };
    ee.data.fd = sock_fd;
    ee.events = EPOLLIN | EPOLLPRI | EPOLLERR | EPOLLHUP;  //EPOLLOUT:socket默认都是可写的，所以这里不加 EPOLLOUT

    if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sock_fd, &ee) == -1)
    {
        LogErr("add server fd to epoll error, errno:%d", errno);
        return false;
    }

    return true;
}

void epoll_del_sock(int epoll_fd, int sock_fd)
{
    struct epoll_event ee = { 0, { 0 } };
    ee.events = EPOLLIN | EPOLLOUT;
    ee.data.u64 = 0;
    ee.data.fd = sock_fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, sock_fd, &ee);
}

void unit()
{

}


int udp_server()
{
    string ip = "127.0.0.1";
    int port = 10240;
    struct sockaddr_in sock_addr;
    {
        bzero(&sock_addr, sizeof(sock_addr));
        sock_addr.sin_family = AF_INET;
        sock_addr.sin_addr.s_addr = ip.empty() == true ? INADDR_ANY : inet_addr(ip.c_str());
        sock_addr.sin_port = htons(port);
    }

    int udp_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(udp_sock < 0)
    {
        LogErr("udp socket() failed, errno:%d", errno);
        return -1;
    }
    if(bind(udp_sock, (struct sockaddr *) &sock_addr, sizeof(sock_addr)) < 0)
    {
        LogErr("udp bind() failed, errno:%d", errno);
        close(udp_sock);
        return -1;
    }

    return udp_sock;
}



void tcp_server()
{
    fstream log_f;
    string ip = "127.0.0.1";
    int port = 10240;

    log_f.open("server.log", ios::out);
    if(log_f.is_open() == false)
    {
        LogErr("open log file failed.errno:%d", errno);
        unit();
    }

    int udp_fd = udp_server();
    if(udp_fd == -1)
    {
        LogErr("create udp sock faile");
        unit();
    }

    int tcp_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(tcp_fd < 0)
    {
        LogErr("socket() failed");
        unit();
    }

    if(set_options(tcp_fd) == false)
    {
        LogErr("server fd set_options failed");
        unit();
    }


    sockaddr_in sock_addr;
    {
        bzero(&sock_addr, sizeof(sock_addr));
        sock_addr.sin_family = AF_INET;
        sock_addr.sin_addr.s_addr = ip.empty() == true ? INADDR_ANY : inet_addr(ip.c_str());
        sock_addr.sin_port = htons(port);
    }

    if(bind(tcp_fd, (sockaddr*) &sock_addr, sizeof(sock_addr)) < 0)
    {
        LogErr("bind failed, errno:%d", errno);
        unit();
    }

    if(listen(tcp_fd, SOMAXCONN) < 0)
    {
        LogErr("epoll_create1 failed, errno:%d", errno);
        unit();
    }

    int epoll_fd = epoll_create1(EPOLL_CLOEXEC);
    if(epoll_fd < 0)
    {
        LogErr("epoll_create1 failed, errno:%d", errno);
        unit();
    }

    if(epoll_add_sock(epoll_fd, tcp_fd) == false)
    {
        LogErr("add server fd to epoll error, errno:%d", errno);
        unit();
    }
    if(epoll_add_sock(epoll_fd, udp_fd) == false)
    {
        LogErr("add server fd to epoll error, errno:%d", errno);
        unit();
    }

    struct epoll_event evs[EP_EVENT_SIZE];
    int run_time = 0;

    while (run_time < 600)
    {
        int nfds = epoll_wait(epoll_fd, evs, EP_EVENT_SIZE, 100);
        for (int i = 0; i < nfds; ++i)
        {
            epoll_event & cur_ev = evs[i];
            int ev_fd = cur_ev.data.fd;
            if(ev_fd == tcp_fd)
            {
                sockaddr_in addr;
                memset(&addr, 0, sizeof(addr));

                socklen_t addr_len = sizeof(addr);
                int conn_fd = accept4(tcp_fd, (sockaddr*) &addr, &addr_len, SOCK_NONBLOCK | SOCK_CLOEXEC);
                if(conn_fd < 0)
                {
                    LogErr("sccept accept error");
                    continue;
                }

                if(set_options(conn_fd) == false)
                {
                    LogErr("new connection set_options error!");
                    close(conn_fd);
                    continue;
                }

                if(epoll_add_sock(epoll_fd, conn_fd) == false)
                {
                    LogErr("add new connection to epoll error!");
                    close(conn_fd);
                }
            }
            else if(ev_fd == udp_fd)
            {
                char buff[ENOUGH_BUFFER_SIZE] = { 0 };
                memset(buff, 0, ENOUGH_BUFFER_SIZE);
                size_t loop_read_size = 0;
                ssize_t read_size = 0;
                struct sockaddr_in clientAddr;
                memset(&clientAddr, 0, sizeof(clientAddr));
                socklen_t len = sizeof(clientAddr);

                while (true)
                {
                    read_size = ENOUGH_BUFFER_SIZE - loop_read_size;
                    ssize_t read_ret = ::recvfrom(udp_fd, buff + loop_read_size, read_size, 0, (struct sockaddr*) &clientAddr, &len);

                    if(read_ret < 0)
                    {
                        if(errno == EAGAIN || errno == EWOULDBLOCK)
                        {
                            break;
                        }
                        else if(errno == EINTR)
                        {
                            continue;
                        }
                        else
                        {
                            epoll_del_sock(epoll_fd, ev_fd);
                            close(ev_fd);

                            break;
                        }
                    }
                    else if(read_ret == 0)
                    {
                        epoll_del_sock(epoll_fd, ev_fd);
                        close(ev_fd);

                        break;
                    }
                    else
                    {
                        loop_read_size += read_ret;
                    }
                }

                if(loop_read_size > 0)
                {
                    LogErr("udp message [%s]", buff);
                    log_f << buff << endl;
                }
            }
            else
            {
                if(cur_ev.events & EPOLLIN || cur_ev.events & EPOLLPRI)
                {
                    char buff[ENOUGH_BUFFER_SIZE] = { 0 };
                    memset(buff, 0, ENOUGH_BUFFER_SIZE);
                    size_t loop_read_size = 0;
                    ssize_t read_size = 0;

                    while (true)
                    {
                        read_size = ENOUGH_BUFFER_SIZE - loop_read_size;
                        ssize_t read_ret = ::read(ev_fd, buff + loop_read_size, read_size);

                        if(read_ret < 0)
                        {
                            if(errno == EAGAIN || errno == EWOULDBLOCK)
                            {
                                break;
                            }
                            else if(errno == EINTR)
                            {
                                continue;
                            }
                            else
                            {
                                epoll_del_sock(epoll_fd, ev_fd);
                                close(ev_fd);

                                break;
                            }
                        }
                        else if(read_ret == 0)
                        {
                            epoll_del_sock(epoll_fd, ev_fd);
                            close(ev_fd);

                            break;
                        }
                        else
                        {
                            loop_read_size += read_ret;
                        }
                    }

                    if(loop_read_size > 0)
                    {
                        LogErr("tcp message [%s] from [%s]", buff);
                        log_f << buff << endl;
                    }
                }
            }
        }
    }

ret_end:
    if(epoll_fd > 0)
    {
        if(tcp_fd > 0)
        {
            epoll_del_sock(epoll_fd, tcp_fd);
        }
        if(udp_fd > 0)
        {
            epoll_del_sock(epoll_fd, udp_fd);
        }

        close(epoll_fd);
    }

    if(tcp_fd > 0)
    {
        close(tcp_fd);
    }
    if(udp_fd > 0)
    {
        close(udp_fd);
    }

    if(log_f.is_open())
    {
        log_f.flush();
        log_f.close();
    }

    return;
}

