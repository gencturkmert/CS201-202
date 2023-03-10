/**
* Title: BST tree
* Author: Mert Gençtürk
* ID: 22003506
* Section: 1
* Assignment: 3
* Description: Dictionary Binary Search Tree implementation
*/

#include "DictionarySearchTree.h"
using namespace std;
class DictionaryBST : public DictionarySearchTree {

public :
	
	 DictionaryBST(string dictionaryFile);
	 void insertItem(TreeNode*& ptr,string item);
	 void insert(string word);
};