/*
 * reverse_list.cpp
 *
 *  Created on: Dec 30, 2015
 *      Author: ruanbo
 */

#include <comm/Log.hpp>
#include <stdlib.h>

struct ListNode
{
    int _data;
    struct ListNode *_next;

    ListNode()
    {
        _data = 0;
        _next = NULL;
    }
};


static void show_list(const ListNode *head)
{
    const ListNode *p = head;
    while(p != NULL)
    {
        LogLine("%d", p->_data);
        if(p->_next)
        {
            LogLine(" --> ");
        }

        p = p->_next;
    }

    Log("");
}


static ListNode* gen_list()
{
    ListNode* head = new ListNode();
    ListNode* p = head;

    for(int i=1; i<10; ++i)
    {
        ListNode* np = new ListNode();
        np->_data = i;

        p->_next = np;
        p = np;
    }

    return head;
}

static void release_list(ListNode* head)
{
    while(head != NULL)
    {
        ListNode* p = head;
        head = head->_next;
        p->_next = NULL;

        delete p;
    }
}

static ListNode* reverse_list(ListNode* head)
{
    if(head == NULL)
    {
        return head;
    }
    ListNode* p1 = head;
    ListNode* p2 = head->_next;
    head->_next = NULL;

    while(p2 != NULL)
    {
        ListNode* tmp = p2->_next;
        p2->_next = p1;
        p1 = p2;
        p2 = tmp;
    }

    return p1;
}

void reverse_list()
{
    ListNode* head = gen_list();
    show_list(head);

    head = reverse_list(head);
    show_list(head);

    release_list(head);
}



