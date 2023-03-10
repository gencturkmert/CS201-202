/**
* Title: Dictionary searcg tree
* Author: Mert Gençtürk
* ID: 22003506
* Section: 1
* Assignment: 3
* Description: Base class for other dictionary tree clasess
*/

#ifndef DICTIONARYSEARCHTREE_H
#define DICTIONARYSEARCHTREE_H
#include <string>
#include <fstream>
#include <iostream>
#include "TreeNode.h"
using namespace std;


//Search tree implementation for the dictionary
class DictionarySearchTree {
public:
	//Constructor that constructs the dictionary from the input file
	DictionarySearchTree(string dictionaryFile);
	//Destructor
	virtual ~DictionarySearchTree();
	//Inserts the given word into the dictionary
	virtual void insert(string word);
	//Searches the given word in the dictionary, and returns the number
	//of comparisons made and whether the word is found or not
	virtual void search(string word, int& numComparisons, bool& found) const;
	//Searches all words in the query file in the dictionary, and
	//summarizes the results in the output file
	virtual void search(string queryFile, string outputFile) const;

	TreeNode* root = NULL;

	DictionarySearchTree();


	//This implementation works both for avl and bst.
	virtual bool searchNode(TreeNode* ptr,string word, int& comp)const ;

	virtual void destroy(TreeNode* ptr);

	void printInorder(TreeNode* node);

	
};


#endif