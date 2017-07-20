/*
 * stl_stack.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"
#include <stack>

void stl_stack_test()
{
    stack<int> s;
    s.push(1);
    int t = s.top();
    s.pop();

    Log("t:%d", t);

}
