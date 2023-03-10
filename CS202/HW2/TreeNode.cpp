/**
* Title : TreeNode
* Author : Mert Gençtürk
* ID: 22003506
* Section : 1
* Assignment : 3
* Description : TreeNode class 
*/
#include "TreeNode.h"

TreeNode::TreeNode() {
	item = "";
	key = NULL;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}

TreeNode::TreeNode(const std::string& nodeItem, TreeNode* left = NULL,
	TreeNode* right = NULL)
	: item(nodeItem), leftChildPtr(left), rightChildPtr(right) 
		{ }


