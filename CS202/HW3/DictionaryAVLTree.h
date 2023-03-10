/**
* Title: AVL tree
* Author: Mert Gençtürk
* ID: 22003506
* Section: 1
* Assignment: 3
* Description: Dictionary AVL Tree implementation
*/

#include "DictionarySearchTree.h"
using namespace std;
class DictionaryAVLTree : public DictionarySearchTree {

public:
	DictionaryAVLTree(string dictionaryFile);
	TreeNode* insertItem(TreeNode*& ptr, string item);
	void insert(string word);


private:
	TreeNode* rotateLeft(TreeNode* root);
	TreeNode* rotateRight(TreeNode*& root);
	int height(TreeNode* ptr);
	TreeNode* balance(TreeNode*& ptr,string word);

};