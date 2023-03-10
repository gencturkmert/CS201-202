#include "DictionaryBST.h"
/**
* Title: BST tree
* Author: Mert Gençtürk
* ID: 22003506
* Section: 1
* Assignment: 3
* Description: Dictionary Binary Search Tree implementation
*/


DictionaryBST::DictionaryBST(string dictionaryFile)
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

void DictionaryBST::insertItem(TreeNode*& ptr,string item)
{

	// Position of insertion found; insert after leaf
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
}
void DictionaryBST::insert(string word)
{
	insertItem(root, word);
}

