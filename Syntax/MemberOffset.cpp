/*
 * MemberOffset.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"


struct S
{
    int _i;
    char _c;
    int _i2;
};


void member_offset_test()
{
    size_t offset = (size_t)(&(((S*)0)->_i2));

    Log("offset:%lu", offset);
}







