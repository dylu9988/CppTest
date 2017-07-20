/*
 * datatype.cpp
 *
 *  Created on: Jun 16, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"


void negative_int()
{
    int i1 = 0xffffffff;
    signed int si1 = 0xffffffff;
    unsigned int ui1 = 0xffffffff;

    Log("i1:%x, si1:%x, ui1:%x", i1, si1, ui1);

    int i2 = 1;
    int i3 = -1;
    unsigned int ui2 = 1;

    cout << i1 << endl;  // -1
    cout << si1 << endl; // -1
    cout << ui1 << endl; // 4294967295
    Log("i2:0x%x, i3:0x%x, ui2:0x%x", i2, i3, ui2);

    int i4 = 0x80000000;  // -2147483648
    int i5 = 0x80000000;  // -2147483648

    //这种方式计算出来的i6=0，明显是不对的，因为(i4+i5)这个运算产生进位了，进位后超过32位
    //但int只能保留32位，所以结果是0
    int i6 = i4 + i5;
    Log("i4:%d, i5:%d, i6:%d", i4, i5, i6);

    unsigned int ui3 = 0x80000000;  // 2147483648
    unsigned int ui4 = 0x80000000;  // 2147483648
    // 同样，这里的运算结果也是0，也同样是因为进位的原因，所以在作整数运算的时候，要考虑溢出的情况，
    // 如果有溢出的可能，应该选用long int 或者　unsigned long int
    unsigned int ui5 = ui3 + ui4;

    Log("ui3:%u, ui4:%u, ui5:%u", ui3, ui4, ui5);
}


void int_char()
{
    int i = 0x00000201;
    char *c = (char*)&i;
    char *c2 = c + 1;

    Log("i:%d, c:%d, c2:%d", i, *c, *c2);
    Log("&i:%p, c:%p, c2:%p", &i, c, c2);
}

void shift_op()
{
    signed int si = -128;

    si = (si << 1);
    Log("si:%d", si);

    si = (si >> 1);
    Log("si:%d", si);

    si = (si >> 1);
    Log("si:%d", si);

}


void datetype_test()
{
//    negative_int();

//    shift_op();

    int_char();

}



