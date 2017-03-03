/*
 * BinarySearch.cpp
 *
 *  Created on: Aug 6, 2016
 *      Author: ruanbo
 */

#include "comm/comm.hpp"


bool binary_search(const vector<int>& A, int L, int R, int key)
{
    if(L > R || A.size() <= R)
    {
        return false;
    }

    int mid = (L + R)/2;

    if(A[mid] == key)
    {
        return true;
    }
    else if(A[mid] < key)
    {
        return binary_search(A, mid+1, R, key);
    }
    else
    {
        return binary_search(A, L, mid-1, key);
    }

    return false;
}




void binary_search_test()
{
    vector<int> A = {1, 3, 5, 7, 9, 10, 30};

    bool ret = binary_search(A, 0, A.size()-1, 8);

    Log("find ret:%d", ret);
}











