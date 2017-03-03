/*
 * stl_string.cpp
 *
 *  Created on: Nov 11, 2016
 *      Author: ruanbo
 */


#include "comm/comm.hpp"



void stlstring_test1()
{
    string s = "pwwkew";

    std::cout << s.substr(2, 4) << std::endl;

    string sub1 = s.substr(2, 4);
    Log("sub string:%s", sub1.c_str());
}

void stl_string_tests()
{
    stlstring_test1();


}


