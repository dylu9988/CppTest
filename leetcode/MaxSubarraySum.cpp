/*
 * MaxSubarraySum.cpp
 *
 *  Created on: Aug 4, 2016
 *      Author: ruanbo
 */

#include "comm/comm.hpp"



int max_subarray(const vector<int>& A)
{
    int ret = 0, sum = 0;
    size_t len = A.size();

    size_t fbegin = 0, fend = 0;
    size_t tbegin = 0, tend = 0;


    for(size_t i=0; i<len; ++i)
    {
        if(sum >= 0)
        {
            sum += A[i];
            tend = i;
        }
        else
        {
            sum = A[i];
            tbegin = i;
        }

        if(sum >= ret)
        {
            ret = sum;

            fbegin = tbegin;
            fend = i;
        }
    }

    if(fbegin <= fend)
    {
        LogLine("[");
        for(size_t i=fbegin; i<= fend; ++i)
        {
            LogLine("%d ", A[i]);
        }
        Log("]");
    }
    return ret;
}


void max_subarray_sum_test()
{
    vector<int> A = {-2, 2, 3, -2, 4, -1, 3};

    int max = max_subarray(A);

    Log("max:%d", max);
}















