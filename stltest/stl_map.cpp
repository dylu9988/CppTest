/*
 * stl_map.cpp
 *
 *  Created on: Oct 28, 2016
 *      Author: ruanbo
 */

#include "comm/comm.hpp"


void multimap_tests()
{
    multimap<int, int> mm;

    mm.insert(make_pair(1, 100));
    mm.insert(make_pair(1, 101));

    for(auto x : mm)
    {
        Log("%d, %d", x.first, x.second);
    }
}


void map_lower_bound()
{
    map<int, int> buf;

    buf[1] = 1001;
    buf[12] = 12001;
    buf[20] = 20001;

    map<int, int>::iterator it = buf.lower_bound(15);

    if(it != buf.end())
    {
        Log("lower bound:%d", it->first);
    }
}



void stl_map_test()
{

//    map_lower_bound();

    multimap_tests();
}





