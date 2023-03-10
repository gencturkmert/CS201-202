/**
* Title: RB tree
* Author: Mert Gencturk
* ID: 22003506
* Section: 1
* Assignment: 4
* Description: RB implementation
*/

#ifndef RBTREE_H
#define RBTREE_H

#include "TreeNode.h"
#include <iostream>

using namespace std;
class RBTree {

public:

	RBTree();
	void insertItem(TreeNode*& ptr, int item,int rb);
	void insert(int item,int rb);

	void inorder();
	void inorder(TreeNode*& ptr);

	TreeNode* root;
};

#endif