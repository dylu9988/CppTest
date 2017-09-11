/*
 * UTS_namespace.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sched.h>
#include <signal.h>
#include <unistd.h>

#define STACK_SIZE (1024 * 1024)
static char container_stack[STACK_SIZE];

char* const container_args[] = {
        "/bin/bash",
        NULL
};

int ipc_container_main(void *arg)
{
    Log("Container - inside the container!");

    sethostname("container", 10);

    execv(container_args[0], container_args);

    return 1;
}

void ipc_namespace()
{
    Log("Parent - start a container!");

    int container_pid = clone(ipc_container_main, container_stack+STACK_SIZE,
            SIGCHLD | CLONE_NEWUTS | CLONE_NEWIPC, NULL);

    if(container_pid == -1)
    {
        Log("clone failed.errno:%d", errno);
        return;
    }

    waitpid(container_pid, NULL, 0);

    printf("Parent - container stopped");

}














