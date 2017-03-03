/*
 * InsertSort.cpp
 *
 *  Created on: Aug 3, 2016
 *      Author: ruanbo
 */

#include "comm/comm.hpp"


/*
 *  插入排序
 */
void insert_help(vector<int>& A, size_t pos)
{
    int key = A[pos];
    while(pos-1>=0 && A[pos-1] > key)
    {
        A[pos] = A[pos-1];
        pos--;
    }

    A[pos] = key;
}

void insert_sort(vector<int>& A)
{
    size_t len = A.size();
    for(size_t i=0; i<len; ++i)
    {
        insert_help(A, i);
    }
}



void insert_sort_test()
{
    vector<int> A = {1, 10, 9, 0, 5, 100, 50, 9};

    insert_sort(A);

    for(auto i : A)
    {
        LogLine("%d ", i);
    }

    Log(" ");
}

