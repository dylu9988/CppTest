

#include "comm/comm.hpp"


class Base
{
public:
    Base()
    {
        Log("Base()");
    }
};

class DBase1 : virtual public Base
{
public:
    DBase1()
    {
        Log("DBase1()");
    }
};
class DBase2 : virtual public Base
{
public:
    DBase2()
    {
        Log("DBase2()");
    }
};

class Driver1 : public DBase2, DBase1
{
public:
    Driver1()
    {
        Log("Driver1()")
    }
};


void multi_inherit_test()
{
    Driver1 d1;
}







