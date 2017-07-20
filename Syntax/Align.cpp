/*
 * Packed.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

class C1
{
    char _c1;
    int _i;
    char _c2;
};

class __attribute__ ((__packed__)) C2
{
    char _c1;
    int _i;
    char _c2;
};


void align_test()
{
    Log("sizeof(C1)=%lu", sizeof(C1));   // 12
    Log("sizeof(C2)=%lu", sizeof(C2));   // 6
}



