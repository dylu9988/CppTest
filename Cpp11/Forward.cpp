/*
 * Forward.cpp
 *
 *  Created on: Jul 12, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

template<typename T>
void _show(T& p)
{
    p = 1;
    cout << "_show(T& p), p=" << p << endl;
}

template<typename T>
void _show(const T& p)
{
    cout << "_show(const T& p), p=" << p << endl;
}

template<typename T>
void show0(T& p)
{
    cout << "show0(T& p) -> ";
    _show(p);
}

template<typename T>
void show0(const T& p)
{
    cout << "show0(const T& p) -> ";
    _show(p);
}

template<typename T>
void show(T&& p)
{
    cout << "show(T&& p) -> ";
    _show(std::forward<T>(p));
}

//template<typename T1, typename T2>
//void show2(T1& p1, T2& p2)
//{
//    _show(p1);
//    _show(p2);
//}


//template<typename T1, typename T2>
//void show2(T1&& p1, T2&& p2)
//{
//    _show(std::forward(p1));
//    _show(std::forward(p2));
//}




void forward_test()
{
    if(false)
    {
        int i = 100;
        int& lri = i;
        const int& clri = i;

        int rri = std::move(i);
        const int ci = 20;

        show0(i);
        show0(lri);
        show0(clri);

        //show0(1);
        show0(rri);
        show0(ci);
    }

    if(true)
    {
        string s = "s";
        const string cs = "cs";
        int i = 22;
        const int ci = 10;

        show(s);
        show(cs);
        show(i);
        show(ci);

        show(100);
    }

    if(false)
    {
        int i = 0;
    }
}















