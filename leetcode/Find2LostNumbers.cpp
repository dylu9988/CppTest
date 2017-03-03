/*
 * Find2LostNumbers.cpp
 *
 *  Created on: Oct 11, 2016
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

#include <math.h>

/*
 *  长度为N-2的数组，所有元素的值都在1-N 之间，且不重复，找出缺失的两个数值。
 */



void find_two_lost_numbers(const vector<int>& A)
{
    int len = A.size();
    int N = len + 2;

    int orign_sum = (N * (N+1)) / 2;   // 1-N 的和
    int orign_square = orign_sum*(2*N + 1) / 3; // 1-N 的平方和

    int sum = 0, square=0;
    int a_plus_b = 0, a_minus_b = 0;

    for(int i=0; i<len; ++i)
    {
        sum += A[i];
        square += A[i] * A[i];
    }

    a_plus_b = orign_sum - sum;
    a_minus_b = sqrt(2*(orign_square-square) - a_plus_b * a_plus_b);

    Log("%d, %d", (a_plus_b + a_minus_b)/2, (a_plus_b - a_minus_b)/2);

}





void find_2_lost_test()
{
    vector<int> A = {1,2,4,6};

    find_two_lost_numbers(A);
}













