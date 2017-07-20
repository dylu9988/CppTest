/*
 * SharedPtr.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"
#include <tr1/memory>

#include "SmartPtr.hpp"

using namespace tr1;

class Item
{
public:
    Item()
    {
        Log("Item()");
    }
    ~Item()
    {
        Log("~Item()");
    }

    void show()
    {
        Log("Item::show()");
    }
};

void shared_ptr_test1()
{
    if(false)
    {
        tr1::shared_ptr<Item> p1 = tr1::shared_ptr<Item>(new Item());
        p1->show();

        tr1::shared_ptr<Item> p2 = tr1::shared_ptr<Item>(new Item());
        p2->show();

        if(p1 == p2)
        {
            Log("p1 == p2");
        }
        else
        {
            Log("p1 != p2");
        }
    }

    if(false)
    {
        tr1::shared_ptr<Item> p1 = tr1::shared_ptr<Item>(new Item());
        p1->show();
    }

    if(true)
    {
        tr1::shared_ptr<Item> p1;

        {
            tr1::shared_ptr<Item> p2 = tr1::shared_ptr<Item>(new Item());
            p1 = p2;
            Log("p2 in scope");
        }

        Log("p2 out of scope");
    }
}

void my_smart_ptr()
{
    if(false)
    {
        SmartPtr<Item> p1 = SmartPtr<Item>(new Item());
        SmartPtr<Item> p2 = SmartPtr<Item>();
    }

    if(true)
    {
        SmartPtr<Item> p1;

        {
            SmartPtr<Item> p2 = SmartPtr<Item>(new Item());
//            p1 = p2;
            Log("p2 in scope");
        }

        Log("p2 out of scope");
    }

}







void shared_ptr_tests()
{
//    shared_ptr_test1();

    my_smart_ptr();

}




