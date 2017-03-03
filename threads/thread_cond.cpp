/*
 * thread_cond.cpp
 *
 *  Created on: Jan 4, 2016
 *      Author: ruanbo
 */


#include <comm/Log.hpp>
#include <stdlib.h>
#include <pthread.h>
#include <vector>
#include <unistd.h>

//#include <thread>



class ThreadData
{
public:
    bool _signal;
    std::vector<int> _data;
    pthread_mutex_t _mutex;
    pthread_cond_t _cond;

    int _seconds;
    int _cnt;
    int _c_cnt;
    int _p_cnt;

public:
    ThreadData()
    {
        _signal = false;
        _seconds = 0;
        _cnt = 0;
        _c_cnt = 0;
        _p_cnt = 0;

        _data.clear();

        pthread_mutex_init(&_mutex, NULL);
        pthread_cond_init(&_cond, NULL);
    }

    ~ThreadData()
    {
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_cond);
    }


    std::vector<int> get_data()
    {
        std::vector<int> ret;

        return ret;
    }

    void add_data()
    {

    }

};


static void *pthread_consumer(void *thread_data)
{
    ThreadData *data = (ThreadData*)thread_data;

    while(true)
    {
        pthread_mutex_lock(&data->_mutex);

        while(!data->_signal)
        {
            pthread_cond_wait(&data->_cond, &data->_mutex);
        }
        data->_signal = false;
//        Log("pthread_consumer=======:%d", data->_c_cnt);
//        data->_c_cnt += data->_cnt;
        data->_c_cnt++;
//        data->_cnt = 0;
        pthread_mutex_unlock(&data->_mutex);

//        usleep(1);
        if(data->_seconds >= 10)
        {
            break;
        }
    }
    return NULL;
}

static void *pthread_producer(void *thread_data)
{
    ThreadData *data = (ThreadData*)thread_data;

    while(true)
    {
        pthread_mutex_lock(&data->_mutex);
//        Log("pthread_producer:%d", data->_p_cnt);
//        data->_cnt++;
        data->_p_cnt++;
        data->_signal = true;
        pthread_cond_signal(&data->_cond);
        pthread_mutex_unlock(&data->_mutex);

//        usleep(1);
        if(data->_seconds >= 10)
        {
            break;
        }
    }

    return NULL;
}

void thread_cond_test()
{
    pthread_t pid_c = 0;
    pthread_t pid_p = 0;

    ThreadData *td = new ThreadData();

    int ret = pthread_create(&pid_c, NULL, pthread_consumer, (void*)td);
    if(ret != 0)
    {
        Log("pthread_create 1 error");
        return;
    }
    ret = pthread_create(&pid_p, NULL, pthread_producer, (void*)td);
    if(ret != 0)
    {
        Log("pthread_create 2 error");
        return;
    }

    while(true)
    {
        td->_seconds++;
        sleep(1);
        if(td->_seconds >= 13)
        {
            break;
        }
    }

    ret = pthread_join(pid_c, NULL);
    if(ret != 0)
    {
        Log("pthread_join 1 error");
        return;
    }
    ret = pthread_join(pid_p, NULL);
    if(ret != 0)
    {
        Log("pthread_join 2 error");
        return;
    }

    Log("c_cnt:%d", td->_c_cnt);
    Log("p_cnt:%d", td->_p_cnt);

    Log("=== end of thread_cond ===");
}






