/*
 * VtablePtr.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: ruanbo
 */



#include "comm/comm.hpp"


class Base
{

public:
    virtual void v()
    {
        Log("Base::v");
    }
    virtual void v2()
    {
        Log("Base::v2");
    }

    void A()
    {
        Log("Base::A");
    }
};


class Driver : public Base
{
public:
    virtual void v()
    {
        Log("Driver::v");
    }
    virtual void v2()
    {
        Log("Driver::v2");
    }

    void A()
    {
        Log("Driver::A");
    }
};

typedef void(*pFun)(void);
typedef void(**ppFun)(void);


void vtable_func_test1()
{
    Base b;
////    b.A();
//    Log("sizeof(pFun):%ld", sizeof(pFun));
//    Log("sizeof(&b):%ld", sizeof(&b));
//    Log("sizeof(int*):%ld", sizeof(int*));
//    Log("sizeof(int):%ld", sizeof(int));

    Driver d1;
    Driver d2;

//    ppFun pd1 = *void(**)(&d1);

//    Log("d1 vtable addr:%ld", (int*)(&d1));
//    Log("d2 vtable addr:%ld", (int*)(&d2));
//
//    Log("d1 first virtual func addr:%ld", (int*)*(int*)(&d1));
//    Log("d1 first virtual func addr:%ld", (int*)*(int*)(&d1));
//
//    pFun d1func = (pFun)(*(int*)*(int*)&d1);
//    d1func();
//
//    pFun d2func = (pFun)(*(int*)*(int*)&d2);
//    d2func();
//
//    pFun d1func2 = (pFun)(*((int*)*(int*)&d1 + 1));
//    d1func2();
}



static void test_func1()
{
    Log("func1");
}
static void test_func2()
{
    Log("func2");
}
static void test_func3()
{
    Log("func3");
}
static void test_func4()
{
    Log("func4");
}

typedef void(*pFunc)(void);

void vtable_func_test2()
{
    pFunc ip_arrar[4] = {test_func1, test_func2, test_func3, test_func4};

//    cout << "test_func1:" << test_func1 << endl;
//    cout << "&test_func1:" << &test_func1 << endl;
//    cout << "*test_func1:" << *test_func1 << endl;

    pFunc tf = test_func1;
    tf();                  //func1

    ip_arrar[0]();   // func1

    pFun p1 = ip_arrar[1];
    p1();           // func2

    (*ip_arrar[1])(); // func2

    ppFun pp = ip_arrar;
    pFunc p0 = pp[0];
    p0();            // func1

    pFunc p2 = pp[2];
    p2();            // func3

    pFunc p3 = pp[3];
    p3();           // func4
}


void vtable_func_ptr_test()
{

    vtable_func_test2();
}















