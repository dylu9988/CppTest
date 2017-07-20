/*
 * vtable.cpp
 *
 *  Created on: Dec 28, 2016
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

class VBase1
{
public:
    virtual void show1()
    {

    }
};

class VBase2
{
public:
    virtual void show2()
    {

    }
};


class MI : public VBase1, public VBase2
{
public:
    virtual void show1()
    {
        Log("show1");
    }
    virtual void show2()
    {
        Log("show2");
    }
};


//多重继承的虚函数调用测试
void vtable_test1()
{
    MI mi;

    VBase1 *vb1 = &mi;
    vb1->show1();       // show1

    {
        VBase2 *vb2 = &mi;
        vb2->show2();   // show2
    }

    {
        VBase2 *vb2 = (VBase2*)vb1;
        vb2->show2();   // show1
    }

    {
        VBase2 *vb22 = dynamic_cast<VBase2*>(vb1);
        vb22->show2();  // show2
    }

}



// 通过指针来调用虚函数
void vtable_test2()
{

}


void vtable_tests()
{
    vtable_test1();


}

