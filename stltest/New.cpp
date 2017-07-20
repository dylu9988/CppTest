/*
 * New.cpp
 *
 *  Created on: Jul 18, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

#include <memory>

class Base
{
private:
    int _data;
public:
    Base()
    {
        _data = 100;

        Log("Base()");
    }

    ~Base()
    {
        Log("~Base()");
    }

    void* operator new(size_t size)
    {
        Log("Base::new(%lu)", size);

        return ::operator new(size);
    }

    void show()
    {
        Log("_data:%d", _data);
    }
};

void new_expression()
{
    Base* p = new Base();

    p->show();

    delete p;
}


void new_tests()
{

}




