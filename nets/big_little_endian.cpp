/*
 * big_little_endian.cpp
 *
 *  Created on: Mar 1, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"
#include <arpa/inet.h>

#include <endian.h>


void nbo_hbo()
{
    short hboi = 0x0103;
    short nboi = htons(hboi);

    show_bin<short>(hboi);
    show_bin<short>(nboi);
}


void big_little_test()
{

    nbo_hbo();
}












