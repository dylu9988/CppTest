/*
 * more_half.cpp
 *
 *  Created on: Dec 30, 2015
 *      Author: ruanbo
 */

#include <comm/Log.hpp>

//static void swap(int &a, int &b)
//{
//    int c = a;
//    a = b;
//    b = c;
//}

static int quick_partition(int*A, int L, int R)
{
    if(A==NULL || L <0 || R<0 || L >= R)
    {
        return -1;
    }

    int key = A[L];
    int p = L;
    for(int i=L+1; i<=R; ++i)
    {
        if(A[i] > key)
        {
            continue;
        }

        A[p] = A[i];
        p++;
        A[i] = A[p];
    }

    A[p] = key;

    return p;
}

static int binary_search(int* A, int L, int R, int K)
{
    if(A==NULL || L < 0 || R < 0 || L > R)
    {
        return -1;
    }

    int mid = (L + R) / 2;
    if(A[mid] == K)
    {
        return mid;
    }
    else if(A[mid] > K)
    {
        return binary_search(A, L, mid-1, K);
    }
    else
    {
        return binary_search(A, mid+1, R, K);
    }
}


void binary_search_test1()
{
    int A[10] = { 1, 2, 3, 4, 10, 11, 12 ,13, 14, 15};
    int ret = binary_search(A, 0, 9, 10);

    Log("binary_search, ret:%d", ret);
}

static int more_than_half(int* A, int Len)
{
    int k = Len / 2;
    int L = 0;
    int R = Len - 1;

    int p = quick_partition(A, L, R);

    while(p != k)
    {
        if(p > k)
        {
            R = p -1;
        }
        else
        {
            L = p + 1;
        }
        Log("k=%d, p=%d, L=%d, R=%d", k, p, L, R);

        p = quick_partition(A, L, R);
    }

    return A[k];
}

void more_than_half()
{
    int a[11] = { 0 };
    a[0] = 2;
    for(int i=1; i<=10; ++i)
    {
        if(i % 2 == 0)
        {
            a[i] = 2;
        }
        else
        {
            a[i] = i;
        }
    }

    for(int i=0; i<11; ++i)
    {
        LogLine("%d  ", a[i]);
    }
    Log("");

//    int p = quick_partition(a, 0, 10);
//
//    for(int i=0; i<11; ++i)
//    {
//        LogLine("%d  ", a[i]);
//    }
//    LogLine(", p=%d", p);

   int ret = more_than_half(a, 11);

    Log("ret:%d", ret);
}






