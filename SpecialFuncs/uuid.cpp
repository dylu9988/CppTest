/*
 * uuid.cpp
 *
 *  Created on: Oct 27, 2016
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

#include <stdio.h>
#include <uuid/uuid.h>


void uuid2string(const uuid_t& uu, char* const str)
{
    for(int i=0; i<16; ++i)
    {
        sprintf(str + i * 2, "%02x", uu[i]);
    }
}


void uuid_test()
{
    uuid_t uu;
    char buf[256] = { 0 };

    uuid_generate(uu);

    uuid2string(uu, buf);

    Log("uuid:%s", buf);

}
