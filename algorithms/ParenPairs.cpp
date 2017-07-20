/*
 * ParenPairs.cpp
 *
 *  Created on: Jul 19, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

/*
 * 合法的括号：
 * e.g: input 3
 * output: ((())), (()()),()()(), ()(()),(())()
 */

static void help(string ret, int l, int r)
{
    if(l < 0 || r < l)
    {
        return;
    }

    if(l == 0 && r == 0)
    {
        Log("%s", ret.data());
    }
    else
    {
        if(l > 0)
        {
            ret += "(";
            help(ret, l-1, r);
        }
        if(r > l)
        {
            ret += ")";
            help(ret, l, r-1);
        }
    }
}
void print_valid_paent()
{
    help("", 3, 3);
}

void paren_paris_test()
{
    print_valid_paent();
}






