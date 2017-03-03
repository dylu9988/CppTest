/*
 * HappyNumber.cpp
 *
 *  Created on: Aug 8, 2016
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

/*
 *  快乐数 :
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1
 */

bool is_happy(int n)
{
    if(n < 0)
    {
        return false;
    }

    set<int> s;
    int ret = n;
    int divider=0, reminder=0;
    while(ret != 1)
    {
        divider = ret;
        while(divider > 0)
        {
            reminder = divider % 10;
            ret += reminder * reminder;
        }

        if(s.count(ret) >= 1)
        {
            return false;
        }
        else
        {
            s.insert(ret);
        }
    }

    return ret == 1;
}









