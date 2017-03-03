/*
 * HeapSort.cpp
 *
 *  Created on: Aug 5, 2016
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

/*
 *  堆排序
 */


void heap_one(vector<int>& A, int idx, int max)
{
    int left = 2 * idx + 1, right = 2 * idx + 2;
    int large = 0;

    if(left <= max && A[idx] < A[left])
    {
        large = left;
    }
    else
    {
        large = idx;
    }

    if(right <= max && A[large] < A[right])
    {
        large = right;
    }

    if(large != idx)
    {
        swap(A[large], A[idx]);

        heap_one(A, large, max);
    }
}


void heap_sort(vector<int>& A)
{
    int len = A.size();
    if(len <= 1)
    {
        return;
    }

    for(int i=len/2-1; i>=0; --i)
    {
        heap_one(A, i, len-1);
    }

    for(int i=len-1; i>=0; --i)
    {
        swap(A[i], A[0]);

        heap_one(A, 0, i-1);
    }
}






void heap_sort_test()
{
    vector<int> A = {1, 10, 0, 9, 5, 100, 50, 9};

    heap_sort(A);

    show_vec(A);
}











