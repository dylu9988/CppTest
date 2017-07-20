/*
 * EventFd.cpp
 *
 *  Created on: Jul 6, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

#include <sys/eventfd.h>
#include <sys/epoll.h>


#define EPOLL_MAX_NUM 4

class EventFd
{
private:


public:
    static void* read_thread(void *argv)
    {
        int efd = (*(int*)argv);
        if(efd <= 0)
        {
            LogError("efd is invalid");
            return NULL;
        }

        int epoll_fd = epoll_create(1024);
        if(epoll_fd == -1)
        {
            LogError("epoll_create failed");
            return NULL;
        }

        struct epoll_event read_event;
        read_event.events = EPOLLIN;
        read_event.data.fd = efd;

        int ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, efd, &read_event);
        if(ret == -1)
        {
            Log("epoll_ctl failed");
            close(epoll_fd);
            return NULL;
        }

        struct epoll_event events[EPOLL_MAX_NUM];
        char buff[128] = { 0 };

        while(true)
        {
            ret = epoll_wait(epoll_fd, events, EPOLL_MAX_NUM, -1);
            if(ret == -1)
            {
                LogError("epoll_wait failed.errno:%d", errno);
                close(epoll_fd);
                return NULL;
            }
            else if(ret == 0)
            {
                Log("epoll_wait TimeOut");
                continue;
            }

            for(int i=0; i<ret; ++i)
            {
                int epoll_event_fd = events[i].data.fd;
                int read_ret = read(epoll_event_fd, buff, 128);
                if(read_ret == -1)
                {
                    LogError("read failed,errno:%d", errno);
                    close(epoll_fd);
                    return NULL;
                }
                else if(read_ret == 0)
                {
                    Log("efd was closed?");
                }
                else
                {
                    Log("read:%s", buff);

                    if(strcmp(buff, "quit") == 0)
                    {
                        close(epoll_fd);
                        return NULL;
                    }
                }
            }

        }
    }


    void run()
    {
        int efd = eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
        if(efd == -1)
        {
            LogError("eventfd failed");
            return;
        }

        pthread_t pid = 0;
        int ret = pthread_create(&pid, NULL, EventFd::read_thread, &efd);
        if(ret == -1)
        {
            LogError("pthread_create failed");
            close(efd);
            return;
        }


        char buff[128] = { 0 };
        for(int i=0; i<10; ++i)
        {
            strcpy(buff, ("data" + std::to_string(i+1)).data());
            ret = write(efd, buff, sizeof(buff));

            sleep(1);
        }

        strcpy(buff, "quit");
        write(efd, buff, sizeof(buff));

        pthread_join(pid, NULL);
        close(efd);

        Log("\nrun end.");
    }
};


void event_fd_test()
{
    EventFd ef;

    ef.run();

    Log("sizeof(helloworld)=%lu", sizeof("helloworld"));

}


