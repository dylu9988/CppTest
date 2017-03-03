/*
 * array.cpp
 *
 *  Created on: Mar 1, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"



//指针数组
//本质是数组，数组里的元素是指针
void pointer_array()
{
    int* a[2] = {NULL, NULL};

    int* p1 = new int;
    int* p2 = new int;

    *p1 = 1;
    *p2 = 20;

    a[0] = p1;
    a[1] = p2;

    Log("p1:%d, p2:%d", *p1, *p2);
    Log("a[0]:%d, a[1]:%d", *a[0], *a[1]);

    delete p1;
    delete p2;
}

//数组指针
//本质是一个指针，指针指向一个数组
void array_pointer()
{
    int arr1[2][2] = {{1, 2}, {10, 20}};
    int (*p1)[2] = arr1;

    Log("p1[0][0]:%d", p1[0][0]);
    Log("p1[0][0]:%d", p1[0][1]);

    Log("p1[1][0]:%d", p1[1][0]);
    Log("p1[1][1]:%d", p1[1][1]);
}

void array_test()
{
//    pointer_array();

    array_pointer();


    Log("end of array_test()");
}


