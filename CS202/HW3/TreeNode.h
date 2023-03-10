/**
* Title : TreeNode
* Author : Mert Gen�t�rk
* ID: 22003506
* Section : 1
* Assignment : 3
* Description : TreeNode class header
*/
#ifndef TREENODE_H
#define TREENODE_H

#include <stdio.h>
#include <string>

class TreeNode { 	// a node in the tree
protected:
	TreeNode();
	TreeNode(const std::string& nodeItem, TreeNode* left,
		TreeNode* right);

	int size();

	std::string item;
	std::string item2;
	std::string midItem;
	int key;// a data item in the tree
	TreeNode* leftChildPtr;	// pointers to children 
	TreeNode* rightChildPtr;
	TreeNode* middleChildPtr;
	TreeNode* tempChild;

	// friend class - can access private parts
	friend class DictionarySearchTree;
	friend class DictionaryBST;
	friend class DictionaryAVLTree;
	friend class Dictionary23Tree;
};





#endif