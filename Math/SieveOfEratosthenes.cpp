/*
 * SieveOfEratosthenes.cpp
 *
 *  Created on: Jul 5, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"
#include <math.h>

/*
 *  诶拉托色尼　筛选法
 */

#define MAX_NUM 1000

void find_primes()
{
    bool flags[MAX_NUM] = { 0 };
    flags[0] = 1;
    flags[1] = 1;

    int prime = 2;

    while(prime < sqrt(MAX_NUM))
    {
        for(int i=prime * prime; i<MAX_NUM; i += prime)
        {
            flags[i] = 1;
        }

        prime++;
        while(prime < MAX_NUM && flags[prime] == 1)
        {
            prime++;
        }
    }

    for(int i=0; i<MAX_NUM; ++i)
    {
        if(flags[i] == 0)
        {
            LogLine("%d ", i);
        }
    }
}

void eratosthenes()
{
    find_primes();
}




