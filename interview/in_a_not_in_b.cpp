/*
 * in_a_not_in_b.cpp
 *
 *  Created on: Dec 30, 2015
 *      Author: ruanbo
 */

#include <vector>



void a_not_b()
{
    char a[100] = { 0 };
    char b[100] = { 0 };

    char hash[255] = { 0 };
    char retc[100] = { 0 };

    for(int i=0; i<100; ++i)
    {
        hash[a[i]] = 1;
    }

    int cidx = 0;
    for(int i=0; i<100; ++i)
    {
        if(hash[b[i]] != 0)
        {
            retc[cidx] = b[i];
            cidx++;
        }
    }

}













