
#ifndef NETS_SIMPLESERVER_HPP_
#define NETS_SIMPLESERVER_HPP_

#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <fstream>

using namespace std;

#define LogErr(...) {printf(__VA_ARGS__); printf("\n"); }

#define EP_EVENT_SIZE  256
#define ENOUGH_BUFFER_SIZE 1024


class SimpleServer
{
private:
    fstream log_f;
    string ip;
    int port;

    int epoll_fd;
    int tcp_fd;
    int udp_fd;

    long int run_time;
    long int test_time;

public:
    SimpleServer();
    virtual ~SimpleServer();
    bool init();
    void unit();

    void run();

private:
    int udp_server();
    bool epoll_add_sock(int epoll_fd, int sock_fd);
    bool set_options(int fd);
    void epoll_del_sock(int epoll_fd, int sock_fd);
};

#endif /* NETS_SIMPLESERVER_HPP_ */








