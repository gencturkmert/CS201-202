#include "DictionaryAVLTree.h"
/**
* Title: AVL tree
* Author: Mert Gençtürk
* ID: 22003506
* Section: 1
* Assignment: 3
* Description: Dictionary AVL Tree implementation
*/

DictionaryAVLTree::DictionaryAVLTree(string dictionaryFile)
{
	ifstream file;
	file.open(dictionaryFile);

	if (!file) {
		cout << "Unable the open file. Please check the path" << endl;
	}
	else {
		string str;
		while (getline(file, str)) {
			this->insert(str);
		}
	}

	file.close();

}

TreeNode* DictionaryAVLTree::insertItem(TreeNode*& ptr, string item)
{
		if (ptr == NULL) {
		ptr = new TreeNode(item, NULL, NULL);
		if (ptr == NULL)
			throw ("TreeException: insert failed");

	}
	// Else search for the insertion position
	else if (item < ptr->item)
		insertItem(ptr->leftChildPtr, item);
	else
		insertItem(ptr->rightChildPtr, item);


	balance(ptr, item);
	return ptr;
}

void DictionaryAVLTree::insert(string word)
{
	root = insertItem(root, word);
	printInorder(root);
	cout << endl;
}

TreeNode* DictionaryAVLTree::rotateLeft(TreeNode* root)
{
	TreeNode* newRoot = root->rightChildPtr;
	TreeNode* leftSubTree = newRoot->leftChildPtr;

	root->rightChildPtr = leftSubTree;
	newRoot->leftChildPtr = root;

	return newRoot;
}

TreeNode* DictionaryAVLTree::rotateRight(TreeNode*& root)
{
	TreeNode* newRoot = root->leftChildPtr;
	TreeNode* rigthSubTree = newRoot->rightChildPtr;

	root->leftChildPtr = rigthSubTree;
	newRoot->rightChildPtr = root;

	return newRoot;
}

int DictionaryAVLTree::height(TreeNode* ptr)
{
	if (ptr == NULL) {
		return 0;
	}
	else if (ptr->leftChildPtr == NULL && ptr->rightChildPtr == NULL) {
		return 1;
	}
	else if (ptr->leftChildPtr == NULL) {
		return 1+height(ptr->rightChildPtr);
	}
	else if (ptr->rightChildPtr == NULL) {
		return 1+ height(ptr->leftChildPtr);
	}
	else {
		int hRight = height(ptr->rightChildPtr);
		int hLeft = height(ptr->leftChildPtr);

		if (hLeft <= hRight)
			return hRight + 1;
		else
			return hLeft + 1;
	}
}

TreeNode* DictionaryAVLTree::balance(TreeNode*& ptr,string word)
{
	int balanceRoot = height(ptr->leftChildPtr) - height(ptr->rightChildPtr);
	if (balanceRoot > 1) {
		if (word < ptr->leftChildPtr->item) {
			ptr = rotateRight(ptr);
			return ptr;
		}
		else if (word > ptr->leftChildPtr->item) {
			ptr->leftChildPtr = rotateLeft(ptr->leftChildPtr);
			ptr = rotateRight(ptr);
			return ptr;
		}

	}
	else if (balanceRoot < -1) {
		if (word > ptr->rightChildPtr->item) {
			ptr = rotateLeft(ptr);
		}
		else if (word < ptr->rightChildPtr->item) {
			ptr->rightChildPtr = rotateRight(ptr->rightChildPtr);
			ptr = rotateLeft(ptr);
			return ptr;
		}

	}
	//balanced
	else {
		return ptr;
	}
}
