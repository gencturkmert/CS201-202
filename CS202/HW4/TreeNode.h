/**
* Title : TreeNode
* Author : Mert Gencturk
* ID: 22003506
* Section : 1
* Assignment : 4
* Description : TreeNode class header
*/
#ifndef TREENODE_H
#define TREENODE_H

#include <stdio.h>
#include <string>

using namespace std;
class TreeNode { 	// a node in the tree

public:
	TreeNode();
	void create234Node(int left, int mid, int right);
	int id;

	string getRep();

protected:

	int size();
	bool isLeaf();
	bool isFull();
	void setRed();
	void setBlack();
	void setRedBlack(int rb);

	int item1;
	int item2; //for 23tree
	int item3; //for 23 tree
	TreeNode* leftChildPtr;	// pointers to children 
	TreeNode* rightChildPtr;
	TreeNode* midLeftChildPtr; // for 23 tree
	TreeNode* midRightChildPtr;; //for 23 tree

	int rb; // 1 red -1 black
	string rep;

		// friend class - can access private parts
	friend class Tree234;
	friend class RBTree;
};





#endif