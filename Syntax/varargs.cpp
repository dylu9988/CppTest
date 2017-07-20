/*
 * varargs.cpp
 *
 *  Created on: Jun 15, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"
#include "stdarg.h"

int calsum(int num,...)
{
    int ret = 0;

    va_list al;
    va_start(al, num);
    while(num > 0)
    {
        ret += va_arg(al, int);
        num--;
    }
    va_end(al);

    return ret;
}

void printf_test()
{
    unsigned int ui = 0xffffffff;
    unsigned char c1=0, c2=0,c3=0;

    Log("c1:%c, c2:%c, c3:%c", c1, ui, c3);
}

void varargs_test()
{
//    int sum = calsum(3, 11, 12, 13);
//    Log("sum:%d", sum);

    printf_test();
}



