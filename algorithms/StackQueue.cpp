/*
 * StackQueue.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: ruanbo
 */



#include "comm/comm.hpp"
#include "string.h"

class KStack
{
#define STACK_SIZE 16
private:
    int _data[STACK_SIZE];
    int _count;

public:
    KStack()
    {
        bzero(_data, sizeof(_data));
        _count = 0;
    }

public:
    bool is_empty()
    {
        return (_count == 0);
    }
    bool is_full()
    {
        return (_count == STACK_SIZE);
    }

    void push(int val)
    {
        if(is_full())
        {
            return;
        }

        _data[_count++] = val;
    }
    int pop()
    {
        if(is_empty())
        {
            return -1;
        }

        _count--;

        return _data[_count];
    }
    int count()
    {
        return _count;
    }
};


class Stack2Queue
{
private:
    KStack _S1;
    KStack _S2;

public:
    Stack2Queue()
    {

    }

public:
    void push_back(int val)
    {
        if(_S1.count() + _S2.count() >= 16)
        {
            return;
        }

        while(_S1.is_empty() == false)
        {
            _S2.push(_S1.pop());
        }

        _S1.push(val);
    }

    int pop_front()
    {
        while(_S2.is_empty() == false)
        {
            _S1.push(_S2.pop());
        }

        if(_S1.is_empty() == true)
        {
            return -1;
        }

        return _S1.pop();
    }



};


void stack_to_queue()
{
    Stack2Queue sq;

    sq.push_back(1);
    sq.push_back(2);
    sq.push_back(3);
    sq.push_back(4);

    Log("%d", sq.pop_front());

    sq.push_back(5);

    Log("%d", sq.pop_front());
    Log("%d", sq.pop_front());

    sq.push_back(6);
    sq.push_back(7);

    Log("%d", sq.pop_front());
    Log("%d", sq.pop_front());
}








