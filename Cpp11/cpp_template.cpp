


#include "comm/comm.hpp"

class MyType1
{
public:
    void show()
    {
        Log("MyType1::show");
    }
};

class MyType2
{
public:
    void show()
    {
        Log("MyType2::show");
    }
};

class TypeA
{
public:
    void show()
    {
        Log("TypeA::show");
    }
};
class TypeB
{
public:
    void show()
    {
        Log("TypeB::show");
    }
};

template<class TType1, class TType2>
class Base
{
public:
    Base()
    {
        Log("Base()");
    }
};

template<>
class Base<TypeA, TypeB>
{
public:
    Base()
    {
        Log("Base() specialization");
    }
};

template<class TType1>
class Base<TType1,TypeB>
{
public:
    Base()
    {
        Log("Base() partial specialization");
    }
};


template<class T1, class T2>
void t_add(T1 t1, T2 t2)
{
    Log("template");
}


template<>
void t_add<int,int>(int t1, int t2)
{
    Log("template specialization");
}

//template<class T>
//void t_add<int,T>(int t1, T t2)
//{
//    Log("template partial specialization");
//}


void cpp_template_test()
{
    Base<MyType1, MyType2> b1;   // Base()

    Base<TypeA, TypeB> b2;       // Base() specialization

    Base<MyType1, TypeB> b3;     // Base() partial specialization

    Base<MyType1, TypeA> b4;     // Base()
}







