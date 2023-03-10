/**
* Title : Binary Search Trees
* Author : Mert Gençtürk
* ID: 22003506
* Section : 1
* Assignment : 2
* Description :Header of Binary Search Tree Class
*/
#ifndef BST_H
#define BST_H

#include "TreeNode.h"
#include <iostream>

class BST {

public:

	TreeNode* root;
	BST();
	BST(const BST& tree);
	~BST();

	bool isEmpty() const;

	int size;


	void searchTreeRetrieve(int searchKey, int& item);
	void insert(const int& newItem);
	void deleteKey(int searchKey);
	int getHeight();
	double medianOfBST();
	void rangeSearch(int a, int b);


	BST& operator=(const BST& rhs);


private :
	void retrieveItem(TreeNode* treePtr, int searchKey,
		int& item);


	void insertItem(TreeNode*& treePtr, const int& item);
	

	void deleteItem(TreeNode*& treePtr, int searchKey);
	void deleteNodeItem(TreeNode*& nodePtr);
	void processLeftmost(TreeNode*& nodePtr, int& item);

	int recHeight(TreeNode* ptr);
	void recMedian(TreeNode* ptr, int& size, int& sum);
	void rangeSearch(TreeNode* ptr,int a, int b);



};




#endif