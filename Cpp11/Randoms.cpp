/*
 * Randoms.cpp
 *
 *  Created on: Jun 17, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

#include <random>
#include <functional>  // std::bind


void normal_random_test()
{
    {
        // 有加随机数种子，每次运行得到的随机数是不一样的
        std::default_random_engine genrator(time(NULL));
        std::uniform_int_distribution<int> dis(100, 200);

        for(int i=1; i<=100; ++i)
        {
            LogLine("%d ", dis(genrator));
            if(i % 10 == 0)
            {
                Log(" ");
            }
        }
        Log(" ");
    }


    {
        //没有加随机数种子，多次运行得到的随机数是一样的
        std::default_random_engine genrator;
        std::uniform_int_distribution<int> dis(100, 200);
        // dis(genrator)调用比较麻烦，可以用std::bind简化
        auto dice = std::bind(dis, genrator);
        for(int i=1; i<=100; ++i)
        {
            LogLine("%d ", dice());
            if(i % 10 == 0)
            {
                Log(" ");
            }
        }
        Log(" ");
    }
}

void random_tests()
{
    srand(time(NULL));

    normal_random_test();
}



