/*
 * NonInheritable.cpp
 *
 *  Created on: Jun 14, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

class A
{
private:
    A()
    {
        Log("A()");
    }
//public:
    ~A()
    {
        Log("~A()");
    }

public:
    static A* inst()
    {
        A* a = new A();
        return a;
    }

    static void delA(A* a)
    {
        delete a;
        a = NULL;
    }

public:
    void show()
    {
        Log("A::show()");
    }
};

//class B : public A
//{
//
//public:
//    B()
//    {
//        Log("B()");
//    }
//};

class SA
{
private:
    SA()
    {
        Log("SA()");
    }
public:
    ~SA()
    {
        Log("~SA()");
    }

public:
    static SA inst()
    {
        SA sa;
        return sa;
    }
};


void non_inheritable_test()
{
    A* a = A::inst();
    a->show();
    A::delA(a);

    SA sa = SA::inst();

//    B* b = new B();

}









