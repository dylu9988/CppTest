/*
 * ipc_sem.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

#include <sys/sem.h>
//#include <sys/ipc.h>

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short* array;
};

int init_sem(int sem_id, int init_val)
{
    union semun sem_union;
    sem_union.val = init_val;

    //SETVAL，表示设置信号量的值
    if(semctl(sem_id, 0, SETVAL, sem_union) == -1)
    {
        Log("semctl SET_VAL failed");
        return -1;
    }

    // GETVAL,表示获取信号量的值
    int now_val = semctl(sem_id, 0, GETVAL, 0);
    Log("after init_sem, sem val:%d", now_val);

    return 1;
}

int del_sem(int sem_id)
{
    union semun sem_union;
    // IPC_RMID：删除一个信号量
    if(semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
    {
        Log("del_sem failed");
        return -1;
    }

    return 1;
}


int sem_p(int sem_id)
{
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = -1;  // -1：Ｐ操作
    sem_b.sem_flg = SEM_UNDO;

    if(semop(sem_id, &sem_b, 1) == -1)
    {
        Log("sem_p failed");
        return -1;
    }

    int now_val = semctl(sem_id, 0, GETVAL, 0);
    Log("after sem_p, sem val:%d", now_val);

    return 1;
}

int sem_v(int sem_id)
{
    struct sembuf sem_b;
    sem_b.sem_num = 0;
    sem_b.sem_op = 1;  // 1 :Ｖ操作
    sem_b.sem_flg = SEM_UNDO;

    if(semop(sem_id, &sem_b, 1) == -1)
    {
        Log("sem_v failed");
        return -1;
    }

    int now_val = semctl(sem_id, 0, GETVAL, 0);
    Log("after sem_v, sem val:%d", now_val);

    return 1;
}


void sem_test1()
{
    // semget()，IPC_CREATE, 创建一个信号量
    int sem_id = semget(ftok(".", 'a'), 1, 0666|IPC_CREAT);
    init_sem(sem_id, 0);  //初始化为0，表示信号量已经被占用

    pid_t ret = fork();
    if(ret == -1)
    {
        Log("fork failed");
        return;
    }

    if(ret == 0)
    {
        // child process
        Log("before child(%d, father(%d)) sleep", getpid(), getppid());
        sleep(5);
        Log("after child(%d, father(%d)) sleep", getpid(), getppid());
        sem_v(sem_id);
    }
    else
    {
        // father process

        Log("father(%d) sem_p op", getpid());

        sem_p(sem_id);

        Log("father(%d) can run now", getpid());

        sem_v(sem_id);
        del_sem(sem_id);
    }

    Log("before exit");
    exit(0);
}


void ipc_sem_tests()
{
    sem_test1();

}







