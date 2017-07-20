/*
 * VtableImpl.cpp
 *
 *  Created on: Jun 13, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

static void print_object(const char* name, void *this_, size_t size)
{
    void **ugly = reinterpret_cast<void**>(this_);

    Log("created %s at address %p of size %zu", name, this_, size);

    for(size_t i=0; i<size/sizeof(void*); ++i)
    {
        Log("  pointer[%zu] == %p", i, ugly[i]);
    }
}



class A
{
public:
    int id;

    A():id(42)
    {
//        Log("A:addr is %p, size is:%zu, id is %d", this, sizeof(*this), this->id);
        print_object(__FUNCTION__, this, sizeof(*this));
    }

    virtual void print()
    {
        Log("A::print");
    }
};
class B
{
public:
    int age;

    B():age(7)
    {
//        Log("B:addr is %p, size is:%zu, age is %d", this, sizeof(*this), this->age);
        print_object(__FUNCTION__, this, sizeof(*this));
    }

    virtual void print()
    {
        Log("B::print");
    }
};
class C : public A, public B
{
public:
    int mode;

    C():mode(-1)
    {
//        Log("C:addr is %p, size if:%zu, id/age/mode are %d,%d,%d", this, sizeof(*this), this->id, this->age, this->mode);
        print_object(__FUNCTION__, this, sizeof(*this));
    }

    virtual void print()
    {
        Log("C::print");
    }
};






void vtable_impl_test()
{
    Log("sizeof(void*)=%ld \n", sizeof(void*));

    C c;

    Log("end of vtable_impl_test");
}









