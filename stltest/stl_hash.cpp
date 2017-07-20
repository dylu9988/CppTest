/*
 * stl_hash.cpp
 *
 *  Created on: Jun 28, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

#include <hash_map>
#include <hash_set>

#include <hashtable.h>

using namespace __gnu_cxx;

void stl_hash_test()
{
    hash_set<int> h;

    Log("h.max_size():%lu", h.max_size());
    Log("h.size():%lu", h.size());

    h.insert(1);
    h.insert(10);
    h.insert(9);

    for(hash_set<int>::const_iterator it=h.begin(); it!=h.end(); ++it)
    {
        LogLine("%d ", *it);
    }

    Log(" ");
    Log("h.max_size():%lu", h.max_size());
    Log("h.size():%lu", h.size());



}



