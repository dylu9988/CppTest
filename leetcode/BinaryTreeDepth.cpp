/*
 * BinaryTreeDepth.cpp
 *
 *  Created on: Apr 26, 2016
 *      Author: ruanbo
 */


#include <comm/Log.hpp>
#include <queue>

struct BinaryTreeNode
{
    int _data;
    BinaryTreeNode *_left;
    BinaryTreeNode *_right;

    BinaryTreeNode(int data)
    {
        _data = data;
        _left = NULL;
        _right = NULL;
    }
};

class BinaryTreeMaxDepth
{

public:
    int get_depth(const BinaryTreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int l_depth = get_depth(root->_left);
        int r_depth = get_depth(root->_right);

        return (l_depth > r_depth ? l_depth + 1 : r_depth + 1);
    }
};



void binary_tree_max_depth()
{

}






