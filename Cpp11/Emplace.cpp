/*
 * VectorEmplace.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"


class VItem
{
private:
    int _data;
public:
    VItem(int data=0)
    {
        _data = data;
        Log("VItem(%d)", data);
    }

    ~VItem()
    {
        Log("~VItem(%d)", _data);
    }

    VItem(const VItem& rhs)
    {
        _data = rhs._data;
        Log("VItem(const VItem& rhs(%d)", _data);
    }

    VItem& operator = (const VItem& rhs)
    {
        _data = rhs._data;
        Log("VItem& operator = (const VItem& rhs(%d)", _data);
        return *this;
    }

    void show()
    {
        LogLine("%d ", _data);
    }
};

void emplace_test()
{
    if(false)   // false
    {
        vector<int> A = {1, 2, 3};
        A.push_back(7);
        A.push_back(8);

        for(auto &i : A)
        {
            LogLine("%d ", i);
        }

        Log(" ");
    }

    if(false)
    {
        vector<int> A = {1, 2, 3};
        A.emplace_back(7);
        A.emplace_back(8);

        for(auto &i : A)
        {
            LogLine("%d ", i);
        }

        Log(" ");
    }

    if(false)
    {
        vector<VItem> v;
        v.reserve(4);
        v.push_back(VItem(1));
        v.push_back(2);
    }
    if(false)
    {
        vector<VItem> v;
        v.reserve(4);
        v.emplace_back(1);
        v.emplace_back(2);
    }

    if(false)
    {
        vector<VItem> v;
        v.reserve(4);
        Log("v.size()=%lu", v.size());
//        v.push_back(std::move(VItem(4)));
//        v.emplace_back(VItem(5));

        v.emplace_back(7);
        v.push_back(8);

//        for(auto &i : v)
//        {
//            i.show();
//        }

        Log(" ");
    }

    if(false)
    {
        vector<int> v;
        v.resize(4);
        Log("v.size()=%lu", v.size());  // v.size()=4
        //输出为:0 0 0 0
        for(auto &i : v)
        {
            LogLine("%d ", i);
        }
        Log(" ");

        vector<int> v2;
        v2.reserve(4);
        Log("v2.size() = %lu", v2.size());  // v2.size() = 0
        // 输出为:空
        for(auto &i : v2)
        {
            LogLine("%d ", i);
        }
    }

    if(false)
    {
        vector<VItem> v;
        v.resize(4);   //会执行４次构造函数

        vector<VItem> v2;
        v2.reserve(4); //不会执行构造函数
    }

    if(false)
    {
        vector<VItem> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
    }
    if(false)
    {
        vector<VItem> v;
        v.reserve(4);
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
    }

    if(true)
    {
        vector<VItem> v;
        v.reserve(4);

        v.emplace_back(1);
        v.emplace_back(2);

        v.insert(v.end(), 3);
        v.emplace(v.end(), 4);
    }

}



