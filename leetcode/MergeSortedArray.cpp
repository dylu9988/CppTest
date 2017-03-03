/*
 * MergeSortedArray.cpp
 *
 *  Created on: Aug 5, 2016
 *      Author: ruanbo
 */

#include "comm/comm.hpp"


/*
 *  合并两个有序数组（从小到大排序），使合并后的数组依旧有序。假设A有足够的空间来容纳B
 */

void merge_sorted(vector<int>& A, int la, const vector<int>& B, int lb)
{
    while(la >= 0 && lb >= 0)
    {
        if(A[la] >= B[lb])
        {
            A[la + lb + 1] = A[la];
            la--;
        }
        else
        {
            A[la + lb + 1] = B[lb];
            lb--;
        }
    }

    while(lb >= 0)
    {
        A[lb] = B[lb];
        lb--;
    }
}


void merge_sorted_array_test()
{
    vector<int> A = {1, 3, 5, 7, 9};
    vector<int> B = {2, 4, 6, 8, 10};

    int la = A.size()-1, lb = B.size()-1;

    A.resize(A.size() + B.size());

    merge_sorted(A, la, B, lb);

    show_vec(A);
}


