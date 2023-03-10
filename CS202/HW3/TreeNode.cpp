/**
* Title : TreeNode
* Author : Mert Gen�t�rk
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
{
	middleChildPtr = NULL;
	item2 = "";
	midItem = "";
	tempChild = NULL;
}

int TreeNode::size()
{
	return (item.empty() ? 0 : 1) + (item2.empty() ? 0 : 1) + (midItem.empty() ? 0 : 1);
}




