/*
 * IsBinarySearchTree.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: ruanbo
 */


#include "comm/comm.hpp"
#include <cmath>
#include <limits.h>

/*
 *  判断一个二叉树是不是二叉查找树
 */


struct BSTNode
{
    int _data;
    BSTNode *_left;
    BSTNode *_right;

    BSTNode()
    {
        _data = 0;
        _left = NULL;
        _right = NULL;
    }
};

using BstPtr = BSTNode*;



/*
 *
 */
int cur_val = 0;
bool is_bst_1(BstPtr root)
{
    if(!root)
    {
        return true;
    }

    if(!is_bst_1(root->_left))
    {
        return false;
    }

    if(cur_val > root->_data)
    {
        return false;
    }
    cur_val = root->_data;

    if(!is_bst_1(root->_right))
    {
        return false;
    }

    return true;
}



class CBstTree
{
    BstPtr _root;

public:
    CBstTree()
    {
        _root = NULL;
    }

    ~CBstTree()
    {
        unit();
    }

public:
    void del_node(BstPtr p)
    {
        LogLine("%d ", p->_data);
        delete p;
        p = NULL;
    }
    void release_node(BstPtr p)
    {
        if(!p)
        {
            return;
        }

        release_node(p->_left);
        release_node(p->_right);
        del_node(p);
    }
    void unit()
    {
        LogLine("release tree:")
        release_node(_root);
        Log(" ");
    }

public:
    void insert_node(int val)
    {
        if(!_root)
        {
            _root = new BSTNode();
            _root->_data = val;
            return;
        }

        BstPtr parent=_root;
        while(parent != NULL)
        {
            if(val <= parent->_data)
            {
                if(parent->_left)
                {
                    parent = parent->_left;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(parent->_right)
                {
                    parent = parent->_right;
                }
                {
                    break;
                }
            }
        }

        BstPtr node = new BSTNode();
        node->_data = val;

        if(val <= parent->_data)
        {
            parent->_left = node;
        }
        else
        {
            parent->_right = node;
        }
    }
    void init_by_order(const vector<int>& A)
    {
        for(auto &i : A)
        {
            insert_node(i);
        }
    }
public:
    void init_by_layer(const vector<int>& A)
    {
        if(_root)
        {
            return;
        }

        int len = A.size();
        if(len <= 0)
        {
            return;
        }

        _root = new BSTNode();
        _root->_data = A[0];

        for(int i=1; i<len; ++i)
        {
            int parent_idx = (i+1) / 2;
            BstPtr parent = nth_node(parent_idx);
            if(!parent)
            {
                break;
            }

            BstPtr child = new BSTNode();
            child->_data = A[i];

            if(i+1 == parent_idx * 2)
            {
                parent->_left = child;
            }
            else
            {
                parent->_right = child;
            }

        }
    }

    //get第N个元素，root为第一个，从上到下，从左到右
    BstPtr nth_node(int N)
    {
        if(!_root || N <= 0)
        {
            return NULL;
        }

        int k = 0;

        queue<BstPtr> stack;
        stack.push(_root);

        while(stack.empty() == false)
        {
            BstPtr p = stack.front();
            stack.pop();

            k++;
            if(k == N)
            {
                return p;
            }

            if(p->_left)
            {
                stack.push(p->_left);
            }
            if(p->_right)
            {
                stack.push(p->_right);
            }
        }

        return NULL;
    }
    void nthnode_test()
    {
        Log("get nth node test:");

        vector<int> A = {1, 3, 5, 2, 2};
        for(auto &i : A)
        {
            BstPtr p = nth_node(i);
            if(p)
            {
                Log("%d th node:%d", i, p->_data);
            }
            else
            {
                Log("%d th node:NULL", i);
            }
        }

        Log("\n");
    }

public:
    bool visit_by_layer(const BstPtr& p, int layer)
    {
        if(!p || layer < 0)
        {
            return false;
        }

        if(layer == 0)
        {
            LogLine("%d ", p->_data);
            return true;
        }

        return visit_by_layer(p->_left, layer-1) + visit_by_layer(p->_right, layer-1);
    }
    void layer_traverse()
    {
        Log("layer_traverse");

        for(int i=0; ; ++i)
        {
            if(visit_by_layer(_root, i) == false)
            {
                break;
            }

            Log(" ");
        }
    }

public:
    void layer_unrecursive()
    {
        Log("layer order unrecursive:");

        queue<BstPtr> stack;

        if(!_root)
        {
            return;
        }

        stack.push(_root);

        while(stack.empty() == false)
        {
            BstPtr p = stack.front();
            stack.pop();

            LogLine("%d ", p->_data);

            if(p->_left)
            {
                stack.push(p->_left);
            }
            if(p->_right)
            {
                stack.push(p->_right);
            }
        }

        Log("\n");
    }

public:
    void post_order(const BstPtr& p)
    {
        if(!p)
        {
            return;
        }

        post_order(p->_left);

        LogLine("%d ", p->_data);

        post_order(p->_right);
    }
    void post_order()
    {
        LogLine("post order visit:");
        post_order(_root);

        Log("\n");
    }

public:
    void in_order(const BstPtr& p)
    {
        if(!p)
        {
            return;
        }
        LogLine("%d ", p->_data);

        in_order(p->_left);

        in_order(p->_right);
    }
    void in_order()
    {
        Log("in order:");
        in_order(_root);
        Log("\n");
    }

public:
    bool is_preorder_valid(const BstPtr p, int &min, int &max)
    {
        if(!p)
        {
            return true;
        }

        if(p->_left)
        {
            bool lret = is_preorder_valid(p->_left, min, p->_data);
            if(lret == false)
            {
                return false;
            }
        }

        if((p->_data < min) || (p->_data > max))
        {
            return false;
        }

        if(p->_right)
        {
            bool rret = is_preorder_valid(p->_right, p->_data, max);
            if(rret == false)
            {
                return false;
            }
        }

        return true;
    }

    bool is_bst_1()
    {
        int min = INT_MIN;
        int max = INT_MAX;

        return is_preorder_valid(_root, min, max);
    }


public:
    void in_order_2()
    {
        LogLine("\nin_order_2: ");

        deque<BstPtr> stack;
        BstPtr p = _root;

        while(stack.empty() == false || p)
        {
            while(p)
            {
                stack.push_back(p);
                p = p->_left;
            }

            p = stack.back();
            stack.pop_back();

            LogLine("%d ", p->_data);

            p = p->_right;
        }

        Log("\n");
    }
};



void is_binary_search_tree_test()
{
    if(false)
    {
        vector<int> A = {50, 25, 75, 15, 30, 60, 100};
//        vector<int> A = {50, 25, 75};

        CBstTree bt;
        bt.init_by_order(A);

        bt.layer_traverse();

//        bt.in_order();

//        bt.post_order();

        bt.nthnode_test();

        bt.layer_unrecursive();
    }

    if(true)
    {
//        vector<int> A = {50, 25, 100, 10, 30, 75, 40};  // not a bst

        vector<int> A = {50, 25, 100, 10, 30, 75, 150};  // is a bst

        CBstTree bt;
        bt.init_by_layer(A);

        bt.layer_traverse();
        bt.in_order_2();

        bool is_bst = bt.is_bst_1();

        if(is_bst)
        {
            Log("above tree is a bst");
        }
        else
        {
            Log("above tree is not a bst");
        }

        Log("\n");
    }
}
















