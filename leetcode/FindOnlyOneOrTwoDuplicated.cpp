/*
 * FindOnlyOneOrTwoDuplicated.cpp
 *
 *  Created on: Oct 13, 2016
 *      Author: ruanbo
 */


#include "comm/comm.hpp"


//数组中有一个只重复1次的数，其它都重复2次，找出这个数
void find_duplicated_one(const vector<int>& A)
{
    int len = A.size();

    int ret = 0;
    for(int i=0; i<len; ++i)
    {
        ret ^= A[i];
    }

    Log("duplicated one:%d", ret);
}


//数组中只有一个数重复2次，其余的重复1次，找出这个数
void find_duplicated_two(const vector<int>& A)
{
    int sum=0, sub=0;

    for(auto & i : A)
    {
        sum += i;
        sub ^= i;
    }

    Log("duplicated two:%d", (sum - sub)/2);
}



#define AND_WITH_N(x, N) (x & (1 << N))


/*
 * 有一个数组，除了两个数只出现1次外，其他的都重复2次，找出这两个数(a,b)
 */
void find_2_duplicates(const vector<int>& A)
{
    int sum = 0, a=0, b=0;

    for(auto &i : A)
    {
        sum ^= i;
    }

    int diff=0;
    while(diff < 32)
    {
        if(AND_WITH_N(sum, diff) >= 1)
        {
            break;
        }

        diff++;
    }

    for(auto &i : A)
    {
        if(AND_WITH_N(i, diff) >= 1)
        {
            a ^= i;
        }
        else
        {
            b ^= i;
        }
    }

    Log("two not duplicated: %d, %d", a, b);
}



/*
 *  一个新的问题：
 *  数组中，除一个数重复1次外，其他的数都重复3次， 找出这个重复1次的数
 *
 *  思路：每个int数都是32位的， 将所有数各个位中为1的个数相加记录下来。
 *       对于相同的数，某一个上的值是否为1都是相同的，
 *       如果全部数都是重复三次的， 那么各个位上1的数量的个数都是3的倍数，
 *       由于有一个重复1次，所以余数位1的时有只重复一次的那个数产生的。
 *
 *       这个方法可以推广到：除一个重复一次外，其他的数都重复2，3， 4， 5……次。
 */
void find_only_one_in_duplicated_three(const vector<int>& A)
{
    int bits[32] = { 0 };
    int ret = 0;

    for(auto &i : A)
    {
        for(int j=0; j<32; ++j)
        {
            if(AND_WITH_N(i, j))
            {
                bits[j]++;
            }
        }
    }

    for(int i=0; i<32; ++i)
    {
        if((bits[i] % 3) == 1)
        {
            ret += (1 << i);
        }
    }

    Log("only on in three:%d", ret);
}


void find_one_two_duplicated_tests()
{
    if(false)
    {
        vector<int> A = {1, 1, 3, 3, 4, 2, 2};
        find_duplicated_one(A);
    }

    if(false)
    {
        vector<int> A = {1, 2, 3, 5, 5, 7};

        find_duplicated_two(A);
    }


    if(false)
    {
        vector<int> A = {1, 1, 4, 5, 5, 2, 2, 9};

        find_2_duplicates(A);
    }

    if(true)
    {
        vector<int> A = {1, 2, 3, 3, 1, 1, 3, 2, 2, 100};

        find_only_one_in_duplicated_three(A);
    }
}












