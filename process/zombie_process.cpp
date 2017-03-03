/*
 * zombie_process.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>


/*
 * 僵尸进程
 */

void sig_chld( int signo ) {
    pid_t pid;
    int stat;
    pid = wait(&stat);
    Log( "child %d exit\n", pid );
}

void make_a_zombie()
{
    //signal(SIGCHLD,  &sig_chld);

    pid_t child = 0;

    if((child = fork()) == -1)
    {
        Log("fork error");
        exit(1);
    }
    else if(child == 0)
    {
        Log("I'm child[%d]", getpid());

        int cnt = 0;
        while(true)
        {
            cnt++;

            if(cnt > 15)
            {
                break;
            }

            Log("pid:%d, ppid:%d", getpid(), getppid());

            sleep(1);
        }
        //sleep(10);
        exit(1);
    }


    int status = -1;
//    wait(&status);

    Log("I'm father");

    //sleep(30);
}

void zombie_process_tests()
{
    make_a_zombie();
}

