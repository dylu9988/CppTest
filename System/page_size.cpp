/*
 * page_size.cpp
 *
 *  Created on: Jun 20, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"


#include <unistd.h>

void get_page_size()
{
    int psize = getpagesize();
    long int psize2 = sysconf(_SC_PAGE_SIZE);

    Log("page size:%d, page size 2:%ld\n", psize, psize2);
}




