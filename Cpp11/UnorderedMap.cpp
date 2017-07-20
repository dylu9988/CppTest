/*
 * UnorderedMap.cpp
 *
 *  Created on: Jul 17, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

#include <unordered_map>

#include <hash_map>
using namespace __gnu_cxx;

void unordered_map_1()
{
    unordered_map<int,int> um;

    {
        Log("after define:");
        Log("um.size():%lu", um.size());
        Log("um.bucket_count():%lu", um.bucket_count());
        Log("um.max_bucket_count():%lu", um.max_bucket_count());
        Log("um.max_size():%lu", um.max_size());

        Log("\n");
    }

    um[1] = 10000;
    um[3] = 30000;

    um.insert(std::make_pair(4, 40000));

    Log("um.size():%lu", um.size());
    for(unordered_map<int,int>::const_iterator it=um.begin(); it!=um.end(); ++it)
    {
        Log("um[%d]=%d", it->first, it->second);
    }

    {
        Log("\nafter add data:");
        Log("um.size():%lu", um.size());
        Log("um.bucket_count():%lu", um.bucket_count());
        Log("um.max_bucket_count():%lu", um.max_bucket_count());
        Log("um.max_size():%lu", um.max_size());

        Log("\n");
    }

//    Log("traverse by c++11 for");
}

void hash_map_test()
{
    hash_map<int,int> hm;
}

void unordered_map_test()
{
//    Log("__cplusplus:%ld", __cplusplus);

    unordered_map_1();
}



