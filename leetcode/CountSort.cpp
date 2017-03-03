/*
 * CountSort.cpp
 *
 *  Created on: Aug 6, 2016
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

void count_sort(vector<int>& A,int N)
{
    vector<int> B;
    B.resize(N);
    for(int i=0; i<N; ++i)
    {
        B[i] = 0;
    }

    int len=A.size();
    for(int i=0; i<len; ++i)
    {
        B[A[i]]++;
    }

    int idx = len - 1;
    for(int i=N-1; i>=0; i--)
    {
        while(B[i] > 0)
        {
            A[idx--] = i;
            B[i]--;
        }
    }
}


void count_sort_test()
{
    vector<int> A = {1, 10, 0, 9, 5, 10, 5, 3};

    count_sort(A, 11);

    show_vec(A);

}

