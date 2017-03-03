/*
 * binary_sort_tree.cpp
 *
 *  Created on: Jan 4, 2016
 *      Author: ruanbo
 */


#include <comm/Log.hpp>

#include "bst_comm.hpp"

/*
 * 二叉排序树
 */



BstNodePtr insert_node(BstNodePtr root, int key)
{
    BstNodePtr node = new BSTNode();
    node->_data = key;

    if(root == NULL)
    {
        return node;
    }

    BstNodePtr parent = root;
    while(true)
    {
        if(key <= parent->_data)
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
            else
            {
                break;
            }
        }
    }

    if(key <= parent->_data)
    {
        parent->_left = node;
    }
    else
    {
        parent->_right = node;
    }

    return root;
}

// 5, 1,9,2,8,3,7,4,6
BstNodePtr gen_bst()
{
    BstNodePtr root = NULL;
    root = insert_node(root, 5);
    root = insert_node(root, 1);

    return root;
}

static void visit_node(BstNodePtr node)
{
    if(node == NULL)
    {
        return;
    }

    LogLine("%d  ", node->_data);
}

static void in_order(BstNodePtr root)
{
    if(root == NULL)
    {
        return;
    }

    in_order(root->_left);
    visit_node(root);
    in_order(root->_right);
}

void binary_sort_tree_test()
{

}

