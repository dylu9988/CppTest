/*
 * FindMoreThenHalf.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: ruanbo
 */


#include "comm/comm.hpp"


/*
 * 数组中，有一个数出现的次数超过数组长度的一半，找出这个数
 *
 *
 */

/*
 *  +-1法， 记录两个值：数组中的一个数ret， 数ret出现的次数times。
 *    times为0时，更新ret，并将times置为1；
 *    times不为1时，如果下一个数组中的值与ret相等，则times++， 否则times--。
 *
 *    因为出现次数超过一半，所以最后的ret值就是我们所要找的。
 */
void more_than_half(const vector<int>& A)
{
    int times = 0, ret = 0;

    for(auto & i : A)
    {
        if(times == 0)
        {
            ret = i;
            times = 1;
        }
        else if(ret == i)
        {
            times++;
        }
        else
        {
            times--;
        }
    }

    Log("ret:%d", ret);
}


/*
 *   可以用局部快排的方法
 */
void more_than_half_2()
{

}


void find_more_than_half()
{
    vector<int> A = {1, 2, 1, 3, 5, 1, 1, 1};

    more_than_half(A);
}
