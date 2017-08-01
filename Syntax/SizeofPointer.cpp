/*
 * SizeofPointer.cpp
 *
 *  Created on: Jul 31, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

void sizeof_ponter_tests()
{
    char* p1 = new char[32];
    Log("sizeof(p1):%lu", sizeof(p1));

    delete [] p1;

}


