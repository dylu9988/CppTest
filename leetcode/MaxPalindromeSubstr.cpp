/*
 * MaxPalindromeSubstr.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: ruanbo
 */



#include "comm/comm.hpp"

/*
 *  查找字符串的最大回文子串
 */

bool is_palindrome(const string& src, int L, int R)
{
    while(L < R)
    {
        if(src[L] != src[R])
        {
            return false;
        }

        L++;
        R--;
    }

    return true;
}


void max_palindrome(const string& src)
{
    int maxlen = 0, start = 0;
    int len = src.length();

    for(int i=0; i<len; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            if((i+j) >= len)
            {
                break;
            }

            if(is_palindrome(src, (i-j), (i+j)) == true)
            {
                if((2 * j + 1) > maxlen)
                {
                    maxlen = 2 * j + 1;
                    start = i - j;
                }
            }
        }
    }

    for(int i=0; i<len; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            if((i+j+1) >= len)
            {
                break;
            }

            if(is_palindrome(src, (i-j), (i+j+1)) == true)
            {
                if((2*j + 2) > maxlen)
                {
                    maxlen = 2*j + 2;
                    start = i - j;
                }
            }
        }
    }

    if(maxlen > 0)
    {
        string substr = src.substr(start, maxlen);

        Log("max palindrome:%s", substr.c_str());
    }
    else
    {
        Log("max palindrome not found");
    }

}



void max_sub_palindrome_str_tests()
{
    {
        string str = "12abccba34";

        max_palindrome(str);
    }
}






















