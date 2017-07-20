/*
 * Move2.cpp
 *
 *  Created on: Jul 12, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

template<typename T>
void foo(T&& p)
{
    Log("foo(T&& p), p=%d", p);
}


void move2_test()
{
    int i = 1;
    foo(i);
    foo(100);
}






