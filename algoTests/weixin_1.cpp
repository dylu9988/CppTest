/*
 * weixin_1.cpp
 *
 *  Created on: Dec 31, 2015
 *      Author: ruanbo
 */

#include <comm/Log.hpp>
#include <vector>

//static void vector1()
//{
//    std::vector<int> v;
//    v.push_back(1);
//
//    for(int i=0; i<v.size(); ++i)
//    {
//        Log("%d ", v[i]);
//    }
//}

void weixin_1()
{
    short a[] = {1,2,3,4,5,6,7,8,9,0};
    char* p = (char*)&a[0];
    char* q = (char*)&a[1];

    Log("1:%d", a[q-p]);

    int* m = (int*)&a[0];
    int* n = (int*)&a[1];
    Log("2:%d", a[n-m]);
}

