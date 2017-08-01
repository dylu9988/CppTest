/*
 * Traits.cpp
 *
 *  Created on: Jul 21, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

template<typename T>
class TypeTraits
{
public:
    static bool isBuiltin()
    {
        return false;
    }
};

template<>
class TypeTraits<int>
{
public:
    static bool isBuiltin()
    {
        return true;
    }
};

template<>
class TypeTraits<unsigned int>
{
public:
    static bool isBuiltin()
    {
        return true;
    }
};

template<>
class TypeTraits<char>
{
public:
    static bool isBuiltin()
    {
        return true;
    }
};

template<>
class TypeTraits<unsigned char>
{
public:
    static bool isBuiltin()
    {
        return true;
    }
};

template<>
class TypeTraits<float>
{
public:
    static bool isBuiltin()
    {
        return true;
    }
};

class TypeItem
{
};

//　将自定义的class定义为Builtin
template<>
class TypeTraits<TypeItem>
{
public:
    static bool isBuiltin()
    {
        return true;
    }
};

template<typename T>
bool checkType(T& t)
{
    return TypeTraits<T>::isBuiltin();
}

void traits_tests()
{
    int a = 0;
    unsigned int b = 1;
    char c = 2;
    float d = 3.0;
    double e = 4.0;

    // a:1, b:1, c:1, d:1, e:0
    Log("a:%d, b:%d, c:%d, d:%d, e:%d",
            checkType(a), checkType(b), checkType(c), checkType(d), checkType(e));

    TypeItem ti;
    Log("ti:%d", checkType(ti));  // ti:1
}









