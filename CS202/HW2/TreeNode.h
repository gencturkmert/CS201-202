/**
* Title : TreeNode
* Author : Mert Gençtürk
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
private:
	TreeNode();
	TreeNode(const std::string& nodeItem, TreeNode* left,
		TreeNode* right);



	std::string item;
	int key;// a data item in the tree
	TreeNode* leftChildPtr;	// pointers to children 
	TreeNode* rightChildPtr;
	TreeNode* middleChildPtr;

	// friend class - can access private parts
	friend class DictionarySearchTree;

};





#endif