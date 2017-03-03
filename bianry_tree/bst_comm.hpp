/*
 * bst_comm.hpp
 *
 *  Created on: Oct 15, 2016
 *      Author: ruanbo
 */

#ifndef BIANRY_TREE_BST_COMM_HPP_
#define BIANRY_TREE_BST_COMM_HPP_




class BSTNode
{
public:
    int _data;
    BSTNode* _left;
    BSTNode* _right;

    BSTNode()
    {
        _data = 0;
        _left = NULL;
        _right = NULL;
    }
};
typedef BSTNode* BstNodePtr;










#endif /* BIANRY_TREE_BST_COMM_HPP_ */
