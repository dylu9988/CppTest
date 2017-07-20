
#include "comm/comm.hpp"

void show(int& i)
{
    Log("lvalue i:%d", i);
}

void show(int&& i)
{
    Log("rvalue i:%d", i);
}

void pre_show(int&& i)
{
    show(i);
}
void test1()
{
    int i = 100;
    show(i);

    show(10);

    pre_show(20);
}

void vector_test()
{
    if(false)
    {
        vector<vector<int> > vv;
        if(true)
        {
            vector<int> v = {1, 2 ,3, 4, 5};
            vv.push_back(v);

            Log("vv.size():%lu, v.size():%lu", vv.size(), v.size());
        }
    }


    if(true)
    {
        vector<vector<int> > vv;
        if(true)
        {
            vector<int> v = {1, 2, 3, 4, 5};
            vv.push_back(std::move(v));

            Log("\nvv.size():%lu, v.size():%lu", vv.size(), v.size());
        }

    }
}


class RAII
{
private:
    char* _str;
    int _len;

private:
    void init_data(int len, const char* str)
    {
        if(_str != NULL)
        {
            delete [] _str;
            _str = NULL;
        }
        if(len == 0)
        {
            return;
        }

        _len = len;
        _str = new char[_len+1];

        strcpy(_str, str);
    }
public:
    RAII()
    {
        _len = 0;
        _str = NULL;

        Log("RAII()");
    }


    ~RAII()
    {
        Log("~RAII()");
        if(_str != NULL)
        {
            delete [] _str;
            _str = NULL;
        }
        _len = 0;
    }

    RAII(const string& str)
    {
        _str = NULL;
        _len = 0;

        Log("RAII(const string& str(%s))", str.data());
        init_data(str.length(), str.data());
    }

    RAII(const RAII& rhs)
    {
        Log("RAII(const RAII& rhs)");
        init_data(rhs._len, rhs._str);
    }

    RAII& operator = (const RAII& rhs)
    {
        Log("RAII& operator = (const RAII& rhs(%d,%s))", rhs._len, rhs._str);
        init_data(rhs._len, rhs._str);
        return *this;
    }
    RAII(RAII&& rhs)
    {
        Log("RAII(RAII&& rhs)");
        _len = rhs._len;
        _str = rhs._str;
        rhs._len = 0;
        rhs._str = NULL;
    }
    RAII& operator = (RAII&& rhs)
    {
        Log("RAII& operator = (RAII&& rhs)");
        _len = rhs._len;
        _str = rhs._str;
        rhs._len = 0;
        rhs._str = NULL;

        return *this;
    }
    void show()const
    {
        Log("_len:%d,_str:%s", _len, _str);
    }
};


RAII get_raii()
{
    Log("enter get_raii()");

    RAII r("Hello");

    Log("just before get_raii() return");

    return r;
}
void raii_show_0(RAII r)
{
    Log("raii_show(RAII r)");
    r.show();
}
void raii_show(const RAII& r)
{
    Log("raii_show(const RAII& r)");
    r.show();
}

void raii_show(const RAII&& r)
{
    Log("raii_show(const RAII&& r)");
    r.show();
}


void raii_swap(RAII& a, RAII& b)
{
    RAII tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

void move_test()
{
    if(true)
    {
        //test1();

        vector_test();
    }

    if(false)
    {
        Log("-----> begin");

        RAII r = get_raii();
        r.show();

        Log("end ----->");
    }

    if(false)
    {
        Log("\ncall raii_show_0(RAII r)");
        RAII r("raii0");
        raii_show_0(r);
    }


    if(false)
    {
        Log("\n\ncall raii_show(const RAII& r)");
        RAII r("Hello");
        raii_show(r);
    }

    if(false)
    {
        Log("\n\ncall raii_show(const RAII&& r)");
        RAII r("raii 3");
        raii_show(std::move(r));
    }

    if(false)
    {
        Log("rr = std::move(r)");

        RAII r("raii 4");
        RAII&& rr = std::move(r);

        raii_show(r);
        raii_show(rr);
    }

    if(false)
    {
        //RAII r1;
        //r1 = RAII("raii 1");
        //r1.show();

        vector<RAII> vec;
        vec.push_back(RAII("raii 2"));
    }

}




