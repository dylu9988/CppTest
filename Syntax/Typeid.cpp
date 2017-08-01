/*
 * Typeid.cpp
 *
 *  Created on: Jul 20, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"
#include <typeinfo>

class TypeId
{
private:
    int _i;

public:
    char _c;
};

class DriverT : public TypeId
{

};



void typedid_tests()
{
    if(false)
    {
        TypeId t1;

        Log("type(t1).name():%s", typeid(t1).name());  // 6TypeId

        TypeId* p = new TypeId();
        Log("type(p).name():%s", typeid(p).name());   // P6TypeId

        int i = 0;
        Log("type(i).name():%s", typeid(i).name());     // i
        Log("type(int).name():%s", typeid(int).name()); // i

        long int li = 0;
        Log("type(li).name():%s", typeid(li).name());    // l
    }

    if(true)
    {
        DriverT *pd = new DriverT();
        TypeId *pb = pd;

        Log("typeid(pb).name():%s", typeid(pb).name());    // P6TypeId
        Log("typeid(*pb).name():%s", typeid(*pb).name());  // 6TypeId
        Log("typeid(pd).name():%s", typeid(pd).name());    // P7DriverT
        Log("typeid(*pd).name():%s", typeid(*pd).name());  // 7DriverT
    }

}




