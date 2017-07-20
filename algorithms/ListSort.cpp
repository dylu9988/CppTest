/*
 * ListSort.cpp
 *
 *  Created on: Jul 5, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"


struct ListNode
{
    int _val;
    ListNode* _next;

    ListNode(int val=0)
    {
        _val = val;
        _next = NULL;
    }
};
typedef ListNode* LPtr;

class ListSort
{
    LPtr _head;

public:
    ListSort()
    {
        _head = NULL;

        vector<int> A = {1, 2, 3, 10, 5, 8, 0, 1, 3, 0,11, 11, 13, 13, 13, 12, 12, 12};
        for(auto &i : A)
        {
            if(!_head)
            {
                _head = new ListNode(i);
            }
            else
            {
                LPtr p = _head;
                while(p->_next)
                {
                    p = p->_next;
                }

                p->_next = new ListNode(i);
            }
        }
    }

public:
    void show()
    {
        LPtr p = _head;
        while(p)
        {
            LogLine("%d ", p->_val);
            p = p->_next;
        }
        Log(" ");
    }


    void sort()
    {
        if(!_head)
        {
            return;
        }

        LogLine("before sort:");
        show();

        LPtr L = _head;
        LPtr R = _head;
        while(R->_next)
        {
            R = R->_next;
        }

        help(L, R);
    }


    void help(LPtr L, LPtr R)
    {
        if(!L || !R || L==R || R->_next == L)
        {
            return;
        }

        int key = L->_val;
        LPtr backp = L;
        LPtr backward = L;
        LPtr forward = L->_next;

        Log("key:%d", key);

        while(forward != R->_next)
        {
            if(forward->_val <= key)
            {
                backward->_val = forward->_val;
                backp = backward;
                backward = backward->_next;
                forward->_val = backward->_val;
            }
            forward = forward->_next;
        }
        backward->_val = key;

        help(L, backp);
        help(backward->_next, R);
    }

    void test()
    {
        sort();

        show();
    }
};

void list_sort_test()
{
    ListSort ls;
    ls.test();
}




