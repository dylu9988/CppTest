/*
 * VectorAddException.cpp
 *
 *  Created on: Jul 22, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

class BaseVA
{
public:
    BaseVA() { Log("BaseVA()"); }
    virtual ~BaseVA()
    {
        Log("~BaseVA()");
    }

    virtual void show()
    {
        Log("BaseVA::show()");
    }

};

class D1 : public BaseVA
{
public:
    D1() { Log("D1()"); }
    ~D1() { Log("~D1()"); }

    void show()
    {
        Log("D1::show");
    }
};


class D2 : public BaseVA
{
public:
    ~D2() { Log("~D2()"); }

    D2()
    {
        Log("D2()");
        throw exception();
    }
    void show()
    {
        Log("D2::show");
    }
};


void pointer_exception_test()
{

    vector<BaseVA*> v;
    v.push_back(new BaseVA());
    v.push_back(new D1());

    if(v.size() > 0)
    {
        BaseVA* p1 = v[0];
        if(p1)
        {
            Log("v[0] is valid, p1:%p", p1);
            p1->show();
        }
    }

    try
    {
        v.push_back(new D2());
    }
    catch (exception &e)
    {
        Log("Exception cauth:%s", e.what());
    }

    Log("2 v.size():%lu", v.size());
    if(v.size() > 0)
    {
        BaseVA* p = v[0];
        if(p)
        {
            Log("v[0] is valid");
            p->show();
        }
    }

    Log("============show=====");
    for(auto &i : v)
    {
        i->show();
    }

    Log("\n============release=====");
    for(auto &i : v)
    {
        delete i;
    }
}


void vector_add_exception()
{
    pointer_exception_test();

}


