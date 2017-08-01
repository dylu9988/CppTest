/*
 * PureVirtualDestructor.cpp
 *
 *  Created on: Jul 22, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

class Base
{
public:
    Base()
    {
        Log("Base()");
    }

    virtual ~Base() = 0;
};

Base::~Base()
{
    Log("~Base()");
}

class Base2
{

};

class Driver : public Base
{
public:
    Driver()
    {
        Log("Driver()");
    }
    ~Driver()
    {
        Log("~Driver()");
    }
};

void pure_virtual_destractor()
{
    if(true)
    {
        Base* p = new Driver();

        delete p;
    }

    if(true)
    {
        Log("sizeof(Base):%lu", sizeof(Base));
        Log("sizeof(Base2):%lu", sizeof(Base2));
    }
}





