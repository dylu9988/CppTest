/*
 * stl_sort.cpp
 *
 *  Created on: May 31, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

#include <algorithm>
#include <functional>

void std_sort_1()
{
    vector<int> L = {1, 3, 5, 9, 7, 8, 6, 4};

    std::sort(L.begin(), L.end());

    for(auto i : L)
    {
        LogLine("%d ", i);
    }

    Log(" ");

    std::sort(L.begin(), L.end(), std::less<int>());
    for(auto &i : L)
    {
        LogLine("%d ", i);
    }
    Log(" ");

    std::sort(L.begin(), L.end(), std::greater<int>());
    for(auto &i : L)
    {
        LogLine("%d ", i);
    }
    Log(" ");

    auto vsize = L.end() - L.begin();
    auto len = std::__lg(vsize * 2);
    Log("vsize:%ld", vsize);
    Log("len:%ld", len);

}

void std__lg_test()
{
    uint32_t ui = 2;

    Log("lead zero count:%d", __builtin_clz(ui));

    Log("one count:%d", __builtin_popcount(ui));

    Log("begin zero count:%d", __builtin_ffs(ui)-1);
}

void stl_sort_test()
{
//    std_sort_1();

    std__lg_test();
}




