/*
 * Final.cpp
 *
 *  Created on: Jul 13, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

class B
{
public:
    virtual void show()
    {
        Log("B::show()");
    }

    void foo()
    {
        Log("B::foo()");
    }
};

class D final : public B
{
public:
    virtual void show() final
    {
        Log("D::show()");
    }

    void foo()
    {
        Log("D::foo()");
    }
};

//class DD : public D
//{
//public:
//    void show()
//    {
//        Log("DD::show()");
//    }
//};


void final_test()
{

}


