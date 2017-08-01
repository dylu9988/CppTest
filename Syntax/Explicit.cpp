/*
 * Explicit.cpp
 *
 *  Created on: Jul 20, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

class NonExplicit
{
    int _i;

public:
    NonExplicit(int data)
    {
        _i = data;
        Log("NonExplicit(%d)", data);
    }
};

class Explicit
{
    int _i;

public:
    explicit Explicit(int data)
    {
        _i = data;
        Log("Explicit(%d)", data);
    }
};


void explicit_tests()
{
    if(false)
    {
        NonExplicit ne = 1;     // NonExplicit(1)，隐式转换
        //NonExplicit ne2;      //　编译出错，因为没有无参构造函数
        NonExplicit ne3(100);   // NonExplicit(100)
        NonExplicit ne4 = 'a';  // NonExplicit(97), 97是a的assic码，隐式转换
        //NonExplicit ne5 = "a"; //编译报错
    }

    if(true)
    {
        //Explicit e = 1;     // 编译报错，class被声明为explicit显示的，不能　隐式转换
        //Explicit e2;      //　编译报错，因为没有无参构造函数
        Explicit e3(100);   // Explicit(100)
        //Explicit e4 = 'a';  // 编译报错，class被声明为explicit显示的，不能　隐式转换
        //NonExplicit e5 = "a"; //编译报错
    }

}



