/*
 * MidValueSort.cpp
 *
 *  Created on: Aug 4, 2016
 *      Author: ruanbo
 */



#include "comm/comm.hpp"

/*
 *  中值排序
 */


void quick_sort_2(vector<int>& A, size_t L, size_t R)
{
    if(A.size() <= R || L >= R)
    {
        return;
    }

    size_t mid = (L + R) / 2, after=L, forward=L;
    int key = A[mid];
    swap(A[mid], A[R]);

    for(; forward<R; ++forward)
    {
        if(A[forward] <= key)
        {
            swap(A[after], A[forward]);
            after++;
        }
    }

    swap(A[after], A[R]);

    quick_sort_2(A, L, after-1);
    quick_sort_2(A, after+1, R);
}



void quick_sort(vector<int>& A, size_t L, size_t R)
{
    if(A.size()<=R || L>=R)
    {
        return;
    }

    size_t mid = (L+R)/2, p=L+1, p2=R;
    int key = A[mid];
    swap(A[L], A[mid]);

    while(p < p2)
    {
        while(A[p] <= key && p < p2)
        {
            p++;
        }

        while(A[p2] > key && p2 > p)
        {
            p2--;
        }

        if(p >= p2)
        {
            break;
        }

        swap(A[p], A[p2]);
    }

    swap(A[L], A[p-1]);

    quick_sort(A, L, p-1);

    quick_sort(A, p, R);
}



void quick_test()
{
    vector<int> A = {1, 10, 0, 9, 5, 100, 50, 9};

    quick_sort_2(A, 0, A.size()-1);

    show_vec(A);

}










