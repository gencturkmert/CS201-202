/**
* Title : Binary Search Trees
* Author : Mert Gençtürk
* ID: 22003506
* Section : 1
* Assignment : 2
* Description : Binary Search Tree Class
*/


#include "BST.h"

BST::BST()
{
	root = NULL;
}
BST::~BST()
{
}

void BST::searchTreeRetrieve(int searchKey,
	int& treeItem) {
	retrieveItem(root, searchKey, treeItem);
}


void BST::retrieveItem(TreeNode* treePtr, int searchKey,
	int& treeItem){

	if (treePtr == NULL)
		throw ("Retrieve failed. Key does not exist");
	else if (searchKey == treePtr->item)
		treeItem = treePtr->item;
	else if (searchKey < treePtr->item)
		retrieveItem(treePtr->leftChildPtr, searchKey, treeItem);
	else
		retrieveItem(treePtr->rightChildPtr, searchKey, treeItem);
}


void BST::insert(const int& newItem) {
	insertItem(root, newItem);
	size++;
}


void BST::insertItem(TreeNode*& treePtr,
	const int& newItem) {

	// Position of insertion found; insert after leaf
	if (treePtr == NULL) {
		treePtr = new TreeNode(newItem, NULL, NULL);
		if (treePtr == NULL)
			throw ("TreeException: insert failed");
	}
	// Else search for the insertion position
	else if (newItem < treePtr->item)
		insertItem(treePtr->leftChildPtr, newItem);
	else
		insertItem(treePtr->rightChildPtr, newItem);
}
void BST::deleteKey(int searchKey)
 {
	size--;
	deleteItem(root, searchKey);
}

void BST::deleteItem(TreeNode*& treePtr, int searchKey) {
	if (treePtr == NULL) // Empty tree
		throw ("Delete failed");

	// Position of deletion found
	else if (searchKey == treePtr->item)
		deleteNodeItem(treePtr);

	// Else search for the deletion position
	else if (searchKey < treePtr->item)
		deleteItem(treePtr->leftChildPtr, searchKey);
	else
		deleteItem(treePtr->rightChildPtr, searchKey);
}

void BST::deleteNodeItem(TreeNode*& nodePtr) {
	TreeNode* delPtr;
	int replacementItem;


	// (1)  Test for a leaf
	if ((nodePtr->leftChildPtr == NULL) &&
		(nodePtr->rightChildPtr == NULL)) {
		delete nodePtr;
		nodePtr = NULL;
	}


	// (2)  Test for no left child
	else if (nodePtr->leftChildPtr == NULL) {
		delPtr = nodePtr;
		nodePtr = nodePtr->rightChildPtr;
		delPtr->rightChildPtr = NULL;
		delete delPtr;
	}
	// (3)  Test for no right child
	else if (nodePtr->rightChildPtr == NULL) {
		delPtr = nodePtr;
		nodePtr = nodePtr->leftChildPtr;
		delPtr->leftChildPtr = NULL;
		delete delPtr;
	}


	// (4)  There are two children:
	//      Retrieve and delete the inorder successor
	else {
		processLeftmost(nodePtr->rightChildPtr, replacementItem);
		nodePtr->item = replacementItem;
	}

}

void BST::processLeftmost(TreeNode*& nodePtr,
	int& treeItem) {

	if (nodePtr->leftChildPtr == NULL) {
		treeItem = nodePtr->item;
		TreeNode* delPtr = nodePtr;
		nodePtr = nodePtr->rightChildPtr;
		delPtr->rightChildPtr = NULL; // defense
		delete delPtr;
	}
	else
		processLeftmost(nodePtr->leftChildPtr, treeItem);
}

int BST::getHeight() {
	return recHeight(this->root);
}

int BST::recHeight(TreeNode* ptr) {
	
	if (ptr == NULL) {
		return 0;
	}
	else if (ptr->leftChildPtr == NULL && ptr->rightChildPtr == NULL) {
		return 1;
	}
	else if (ptr->leftChildPtr == NULL) {
		return recHeight(ptr->rightChildPtr);
	}
	else if (ptr->rightChildPtr == NULL) {
		return recHeight(ptr->leftChildPtr);
	}
	else {
		int hRight = recHeight(ptr->rightChildPtr);
		int hLeft = recHeight(ptr->leftChildPtr);

		if (hLeft <= hRight)
			return hRight + 1;
		else
			return hLeft + 1;
	}
}

double BST::medianOfBST() {
	int size = 0;
	int sum = 0;

	recMedian(this->root, size, sum);

	return ((double)sum) / size;
}

void BST::recMedian(TreeNode* ptr, int& size, int& sum) {

	if (ptr != NULL) {
		size++;
		sum = sum + ptr->item;

		recMedian(ptr->leftChildPtr,size,sum);
		recMedian(ptr->rightChildPtr,size,sum);
	}
}


void BST::rangeSearch(int a, int b) {

	rangeSearch(this->root, a, b);

}


void BST::rangeSearch(TreeNode* ptr,int low,int high) {

	if (ptr == NULL) {
		return;
	}

	if (ptr->item< low) {
		rangeSearch(ptr->rightChildPtr, low, high);

	}
	else if(ptr->item>high) {
		rangeSearch(ptr->leftChildPtr, low, high);
	}
	else {
		std::cout<< ptr->item<<" ";
		rangeSearch(ptr->rightChildPtr, low, high);
		rangeSearch(ptr->leftChildPtr, low, high);

	}
}





