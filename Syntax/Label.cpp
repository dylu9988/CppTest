/*
 * Label.cpp
 *
 *  Created on: Jul 20, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

void label_tests()
{
    Log("label tests begin");

    return;  // 如果不return的话，会执行 label1，label2　处的代码

label1:
    Log("to label1");

label2:
    Log("to label2");

}



