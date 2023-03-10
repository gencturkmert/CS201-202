/**
* Title: 23Tree
* Author: Mert Gençtürk
* ID: 22003506
* Section: 1
* Assignment: 3
* Description: Dictionary 23 Tree implementation
*/
#include "DictionarySearchTree.h"
using namespace std;
class Dictionary23Tree : public DictionarySearchTree {
public:
	Dictionary23Tree(string dictionaryFile);
	 ~Dictionary23Tree();
	TreeNode* insertItem(TreeNode*& ptr, string item,TreeNode* parent);

	void insert(string word);
	void search(string word, int& numComparisons, bool& found) const;
	void search(string queryFile, string outputFile) const;


private:
	
	TreeNode* splitAndMove(TreeNode*& ptr, string word,TreeNode* parent);
	void destroy(TreeNode* ptr);
	bool searchNode(TreeNode* ptr, string word, int& comp) const;


};