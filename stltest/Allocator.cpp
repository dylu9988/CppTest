/*
 * Allocator.cpp
 *
 *  Created on: Jul 18, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

#include <ext/new_allocator.h>

class Item
{
private:
    int _data;
public:
    Item(int data = 0)
    {
        _data = data;
    }

};

void vector_1()
{
    vector<Item> v;

    Log("v.size()=%lu", v.size());

    v.push_back(Item(1));
    v.push_back(Item(2));
    v.push_back(Item(3));

}


void allocator_tests()
{
    vector_1();

}






