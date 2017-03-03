/*
 * LinerSearch.cpp
 *
 *  Created on: Aug 6, 2016
 *      Author: ruanbo
 */


#include "comm/comm.hpp"


bool liner_search(const vector<int>& A, int key)
{
    size_t len = A.size();
    for(size_t i=0; i<len; ++i)
    {
        if(A[i] == key)
        {
            return true;
        }
    }

    return false;
}

