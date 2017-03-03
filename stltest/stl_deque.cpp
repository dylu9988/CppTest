/*
 * stl_deque.cpp
 *
 *  Created on: Oct 27, 2016
 *      Author: ruanbo
 */

#ifndef STL_DEQUE_CPP_
#define STL_DEQUE_CPP_


#include "comm/comm.hpp"


struct DequeNode
{
    int val;

    DequeNode(int v)
    {
        val = v;
    }
};

void push_pop_test()
{
    deque<DequeNode*> s1;
    deque<DequeNode*> s2;

    s1.push_back(new DequeNode(1));
    s2.push_back(NULL);

    DequeNode* p1 = NULL;
    DequeNode* p2 = NULL;

    while(s1.empty()==false && s2.empty()==false)
    {
        if(!p1 && !p2)
        {
            p1 = s1.back();
            p2 = s2.back();

            s1.pop_back();
            s2.pop_back();
        }

        if((p1 && !p2) || (!p1 && p2))
        {
            Log("not the same");
        }

        p1 = NULL;
        p2 = NULL;
    }


}


void stldeque_tests()
{
    push_pop_test();

    Log("end of stl deque test");
}


#endif /* STL_DEQUE_CPP_ */
