/*
 * ReverseInteger.cpp
 *
 *  Created on: Apr 18, 2016
 *      Author: ruanbo
 */


#include <comm/Log.hpp>
#include <limits.h>
#include <algorithm>  // std::reverse()

class ReverseBits
{
private:
    void swap_bit(int& n, int i, int j)
    {
        int bi = (n & (0x01 << i));
        int bj = (n & (0x01 << j));

        n = n & ~(0x01 << i);
        n = n & ~(0x01 << j);

        if(bi > 0)
        {
            n = n | (0x01 << (31 - i));
        }

        if(bj > 0)
        {
            n = n | (0x01 << (31 - j));
        }
    }

    void show_bin(int n)
    {
        std::string str = "";
        for(int i=0; i<32; ++i)
        {
            if(n % 2 == 0)
            {
                str += "0";
            }
            else
            {
                str += "1";
            }

            n = n / 2;
        }

        std::reverse(str.begin(), str.end());

        Log("%s", str.c_str());
    }
public:
    int reverse_bites(int n)
    {
        for(int i=0, j=31; i<j; ++i, --j)
        {
            swap_bit(n, i, j);
        }

        return n;
    }

    void bit_tests()
    {
        if(false)
        {
            int n = 10;

            int i = (n & (0x01 << 3));


            show_bin(n);
            show_bin(i);

            n = n & ~(0x01 << 3);
            show_bin(n);
        }

        if(true)
        {
            int n = 10;
            show_bin(n);
            n = reverse_bites(n);
            show_bin(n);
        }
    }
};


/*
 * integer的范围： -2147483648  <= N <= 2147483647
 * N = N1 reverse
 *  如果 N1 是九位数，则翻转后（N）不会溢出；
 *  如果 N1 是十位数，则个位数只能是 1 或者 2，否则会溢出；  （N1的个位为 N 的 十亿位）
 *    如果 N1的个位数是2，则是位数必须小于等于1，（N1的十位为N的亿位）
 *    如果 N1的十位数是1，则百位数必须小于等于4，（N1的百位为N的千万位）
 *    如果 N1的百位数是7，则千位数必须小于等于7，（N1的千位为N的百万位）
 *    以此类推。。。
 */


class ReverseInteger
{
private:
    bool is_overflow(int n)
    {
        if( -1000000000 <= n && n <= 1000000000)
        {
            return false;
        }
        else if(n == INT_MIN)
        {
            return true;
        }

        if(n < 0)
        {
            n = -n;
        }

        // bound = 463847412,
        /* n的值为 dxxxxxxxxx : 十为数
         * N1 = reverse n, N1的临界值为：2147483647。
         * n的临界值为：d463847412 -> N1 = 214748364d, d的值为1或2，因为n本身不溢出；1/2小于7(2147483647的个位数)，所以不用考虑了。
         *
         *
         *
         */
        int bound = reverse_integer(INT_MAX/10);  // 463847412
        for(; bound != 0; bound=bound/10, n=n/10)
        {
            if(bound%10 > n%10)
            {
                return false;
            }
            else if(bound%10 < n%10)
            {
                return true;
            }
        }

        return false;
    }

    int reverse_integer(int n)
    {
        int ret = 0;
        bool negative = false;
        if(n < 0)
        {
            negative = true;
            n = -n;
        }

        while(n > 0)
        {
            int last = n % 10;
            n = n / 10;

            ret = (ret * 10 ) + last;
        }

        if(negative)
        {
            ret = - ret;
        }

        return ret;
    }
public:
    int reverse(int n)
    {
        if(is_overflow(n))
        {
            return -1;
        }

        int ret = 0;


        return ret;
    }
};








void reverse_integer_test()
{
    {
        ReverseInteger ri;

        Log("INT_MAX:%d", INT_MAX);
        Log("INT_MIN:%d", INT_MIN);

        int n = -1230;

        int r = ri.reverse(n);

        Log("%d reverse get: %d", n ,r);
    }

    {
        ReverseBits rb;
        rb.bit_tests();
    }
}

