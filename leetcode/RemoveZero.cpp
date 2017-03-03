/*
 * RemoveZero.cpp
 *
 *  Created on: Aug 3, 2016
 *      Author: ruanbo
 */

#include "comm/comm.hpp"


void RemoveZero(vector<int>& A)
{
    if(A.size() <= 1)
    {
        return;
    }

    int i=0, j=1, len = A.size();
    while(j < len)
    {
        while(i < len && A[i] != 0)
        {
            i++;
        }

        j = i;
        while(j < len && A[j] == 0)
        {
            j++;
        }

        if(j >= len || i >= len)
        {
            break;
        }

        A[i++] = A[j];
        A[j] = 0;
    }

    while(i < len)
    {
        A[i++] = 0;
    }

}


void remove_zero_test()
{
    vector<int> v{0, 1, 3, 0, 9};

    RemoveZero(v);

    for(auto i : v)
    {
        LogLine("%d ", i);
    }

    Log(" ");
}












