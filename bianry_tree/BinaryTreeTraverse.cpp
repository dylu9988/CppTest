/*
 * BinaryTreeTraverse.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: ruanbo
 */



#include <comm/Log.hpp>
#include <queue>


struct BinaryTreeNode
{
    int _data;
    BinaryTreeNode* _left;
    BinaryTreeNode* _right;

    BinaryTreeNode(int data) : _data(data), _left(NULL), _right(NULL)
    {

    }
};

typedef BinaryTreeNode* BtnPtr;


class BinaryTreeTraverse
{
public:
    virtual ~BinaryTreeTraverse()
    {
        del_node(_root);
    }

private:
    BtnPtr _root;
public:
    void del_node(BtnPtr root)
    {
        if(root == NULL)
        {
            return;
        }

        if(root->_left)
        {
            del_node(root->_left);
        }
        if(root->_right)
        {
            del_node(root->_right);
        }

        delete root;
        root = NULL;
    }
    void add_node(int val)
    {
        BtnPtr new_node = new BinaryTreeNode(val);
        if(_root == NULL)
        {
            _root = new_node;
            return;
        }

        BtnPtr i = _root;
        BtnPtr p = _root;
        while(p != NULL)
        {
            i = p;

            if(val <= p->_data)
            {
                p = p->_left;
            }
            else
            {
                p = p->_right;
            }
        }

        if(val <= i->_data)
        {
            i->_left = new_node;
        }
        else
        {
            i->_right = new_node;
        }
    }

    void visit_node(BtnPtr p)const
    {
        if(p == NULL)
        {
            return;
        }

        Log("%d ", p->_data);
    }
public:
    void pre_order(BtnPtr root)const
    {
        if(root == NULL)
        {
            return;
        }

        Log("%d ", root->_data);
        pre_order(root->_left);
        pre_order(root->_right);
    }
    //前序遍历, 根 ->  左 -> 右
    void pre_order()const
    {
        pre_order(_root);
    }
    void pre_order_non_recursive(BtnPtr root)const
    {
        std::queue<BtnPtr> stack;
        while(root)
        {
            visit_node(root);

            if(root->_right != NULL)
            {
                stack.push(root->_right);
            }

            if(root->_left)
            {
                root = root->_left;
            }
            else
            {
                root = stack.front();
                stack.pop();
            }
        }
    }
    //非递归前序遍历, 根 ->  左 -> 右
    void pre_order_non_recursive()const
    {
        if(_root == NULL)
        {
            return;
        }

        BtnPtr p = _root;
        std::queue<BtnPtr> stack;
        while(p || stack.empty() == false)
        {
            while(p)
            {
                visit_node(p);

                stack.push(p);
                p = p->_left;
            }

            p = stack.front();
            stack.pop();

            p = p->_right;
        }

    }


public:
    void in_order(BtnPtr root)const
    {
        if(root == NULL)
        {
            return;
        }

        in_order(root->_left);
        visit_node(root);
        in_order(root->_right);
    }
    //中序遍历， 左 ->  根 -> 右
    void in_order()const
    {
        in_order(_root);
    }

    //递归中序遍历， 左 ->  根 -> 右
    void in_order_non_recursive()const
    {
        if(_root == NULL)
        {
            return;
        }

        BtnPtr p = NULL;
        std::queue<BtnPtr> stack;
        stack.push(p);
        while(p!=NULL || stack.empty() == false)
        {
            while(p)
            {
                stack.push(p);
                p = p->_left;
            }

            p = stack.front();
            stack.pop();

            visit_node(p);

            p = p->_right;
        }
    }


public:
    BtnPtr invert(BtnPtr root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        BtnPtr tmp = root->_left;
        root->_left = invert(root->_right);
        root->_right = invert(tmp);

        return root;
    }
    // 反转二叉树
    void invert()
    {
        _root = invert(_root);
    }
};







