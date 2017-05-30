/*
 * time_date.cpp
 *
 *  Created on: Mar 15, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

#include <ctime>
#include <iomanip>  // std::put_time()
#include <chrono>
#include <sstream>   // std::stringstream

void get_delta_time()
{
    auto start = chrono::system_clock::now();
    auto tstart = time(NULL);
    auto t1 = chrono::system_clock::to_time_t(start);  // 与 time(NULL)的值是一样的
    Log("tstart:%ld, t1:%ld", tstart, t1);

    int sum = 0;
    for(int i=0; i<1000000; ++i)
    {
        for(int j=0; j<2000; ++j)
        {
            sum = i + j;
        }
    }

    auto end = chrono::system_clock::now();
    auto tend = time(NULL);

    auto diff = chrono::duration_cast<chrono::microseconds>(end - start);  // 微秒
    auto diffmls = chrono::duration_cast<chrono::milliseconds>(end - start); //毫秒
    auto diffs = chrono::duration_cast<chrono::seconds>(end - start);       //秒
    Log("delta time:%ld微秒", diff.count());
    Log("delta time:%ld毫秒", diffmls.count());
    Log("delta time:%ld秒", diffs.count());
    Log("delta ttime:%ld秒", (tend - tstart));
}

void format_time()
{
    std::time_t now = time(NULL);

    char buf[32] = { 0 };
    std::strftime(buf, 32, "%Y:%m:%d", std::localtime(&now));
    Log("now date:%s", buf);

    string date_str(buf, 0, strlen(buf));
    Log("now date:%s", date_str.data());

//
//    std::stringstream sst;
//    std::tm tm = *std::localtime(&now);
//    sst << std::put_time(&tm ,"%Y:%m:%d");
//    string fmt_time = sst.str();
//    Log("now put_time date:%s", fmt_time.data());
//
//    sst.clear();
//    sst.str("");
//    sst << std::put_time(&tm, "%H:%M:%S");
//    Log("now put_time time:%s", sst.str().data());

}

void time_date_tests()
{
    get_delta_time();

//    format_time();
}



