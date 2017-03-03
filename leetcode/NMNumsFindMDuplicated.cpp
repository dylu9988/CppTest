/*
 * NMNumsFindMDuplicated.cpp
 *
 *  Created on: Oct 10, 2016
 *      Author: ruanbo
 */


#include "comm/comm.hpp"


/*
 * 数组有N+M个元素，值的范围为 1 - N， 打印出所用重复的元素
 *
 * 这里有一个问题，就是：范围为1-N，是不是连续的。
 */


//这个以连续来处理
/*
 *  遍历每个元素，前N个元素分别存放：1， 2， 3 …… N，即：A[0]=1, A[1]=2, A[2]=3……
 *  因为元素的值包含 1-N 的所有值，所以不会出现漏掉的情况。
 *  遍历完之后，【N+1， M】的元素就是重复的值了。
 */
void find_m_dumplicated_1(vector<int>& A, int N)
{
    int len = A.size();


    for(int i=0; i<len; ++i)
    {
        int val = A[i];

        if(val == i+1)  // 在自己的位置上
        {
            continue;
        }
        else
        {
            if(val != A[val-1])
            {
                std::swap(A[i], A[val-1]);
            }
            else
            {
                //LogLine("%d ", val);
            }
        }
    }

    for(int i=N; i<len; ++i)
    {
        LogLine("%d ", A[i]);
    }


    Log(" ");

}

/*
 * 思路：采用标记法，遍历所有元素，每个元素的值对应与数组的下标。第一次的时候将值取负，注意不能设为-1 之类的，
 * 因为还要各个元素的真实值。
 */
void find_m_dumplicated_3(vector<int>& A, int N)
{
    int len = A.size();

    for(int i=0; i<len; ++i)
    {
        int val = std::abs(A[i]);

        if(A[val-1] > 0)
        {
            A[val-1] = - A[val-1];
        }
        else
        {
            LogLine("%d ", val);
        }
    }

    Log(" ");
}

void find_m_dumplicated_2(vector<int>& A)
{
    int len = A.size();
    if(len <= 0)
    {
        return;
    }

    int key = A[0];

    for(int i=1; i<len; ++i)
    {
        int val = A[i];

        if(A[val-1] != val)
        {
            key = A[val-1];
            A[val-1] = val;
        }
        else
        {
            if(val-1 != i)
            {
                LogLine("%d ", key);
            }
        }
    }


}


void find_m_duplicated_test()
{
    vector<int> V = {4, 4, 5, 4, 2, 2, 1, 5, 3};

    show_vec(V, "array before");
    find_m_dumplicated_3(V, 5);

    show_vec(V, "array after");

    Log(" ");
}



