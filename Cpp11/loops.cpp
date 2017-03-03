/*
 * loops.cpp
 *
 *  Created on: Apr 21, 2016
 *      Author: ruanbo
 */


#include <comm/Log.hpp>
#include <map>
#include <vector>





void cpp11_loop()
{

    {
        std::map<int, std::string> map;
        map[1] = "robert";
        map[3] = "test";

        for(const auto& kvp : map)
        {
            Log("map[%d] = %s", kvp.first, kvp.second.c_str());
        }
    }

    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(10);
        vec.push_back(3);

    }

    {
        int arr[] = {1,3,5,7,8,10};

        LogLine("arr:");
        for(int i : arr)
        {
            LogLine(" %d ", i);
        }
        Log(" ");


        for(int &i : arr)
        {
            i = i * i;
        }

        LogLine("arr:");
        for(int i : arr)
        {
            LogLine(" %d ", i);
        }
        Log(" ");

        for(int i : arr)
        {
            i = i * i;
        }

        LogLine("arr:");
        for(int i : arr)
        {
            LogLine(" %d ", i);
        }
        Log(" ");

    }
}







