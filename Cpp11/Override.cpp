/*
 * Override.cpp
 *
 *  Created on: Jul 16, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

class Base
{
public:
    virtual void show()const
    {
        Log("Base::show()");
    }
};

class Driver : public Base
{
public:
    void show()const override
    {
        Log("Driver::show()");
    }
};


void override_tests()
{
    Base* bp = new Driver();
    bp->show();
}




