/*
 * SelectSort.cpp
 *
 *  Created on: Aug 4, 2016
 *      Author: ruanbo
 */

#include "comm/comm.hpp"


/*
 * 选择排序
 */



size_t select_min(const vector<int>& A, size_t L, size_t R)
{
    size_t pos = L;
    int min = A[L];
    for(; L<=R; ++L)
    {
        if(A[L] <= min)
        {
            pos = L;
            min = A[L];
        }
    }

    return pos;
}


void select_sort(vector<int>& A)
{
    size_t len = A.size();

    for(size_t i=0; i<len; ++i)
    {
        size_t pos = select_min(A, i, len-1);
        swap(A[i], A[pos]);
    }
}


void select_sort_test()
{
    vector<int> A = {1, 10, 0, 9, 5, 100, 50, 9};

    select_sort(A);

    show_vec(A);
}


