#ifndef TREE234_H
#define TREE234_H

#include "TreeNode.h"
#include <iostream>
#include <string>

using namespace std;
class Tree234{


public:

	Tree234();
	TreeNode* insertItem(TreeNode*& ptr, int item);
	void insert(int item);

	void inorder();
	void inorder(TreeNode*& ptr);

	void insert(TreeNode*& newNode);
	void insert(TreeNode*& newNode, TreeNode*& ptr);

	void assignIds(int& id,TreeNode*& ptr);
	int assignIds();


	string traverse();
	string traverse(TreeNode*& ptr);

	TreeNode* root;
};




#endif