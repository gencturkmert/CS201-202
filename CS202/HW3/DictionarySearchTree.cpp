/**
* Title: Dictionary searcg tree
* Author: Mert Gençtürk
* ID: 22003506
* Section: 1
* Assignment: 3
* Description: Base class for other dictionary tree clasess
*/

#include "DictionarySearchTree.h"

DictionarySearchTree::DictionarySearchTree()
{
	root = NULL;
	cout << "NULL DIC" << endl;
}

DictionarySearchTree::DictionarySearchTree(string dictionaryFile) {
	ifstream file;
	file.open(dictionaryFile);

	if (!file) {
		cout << "Unable the open file. Please check the path" << endl;
	}else{
		string str;
		while (getline(file,str)) {
			this->insert(str);
		}
	}

	file.close();

}
DictionarySearchTree::~DictionarySearchTree()
{
	if (root != NULL) {
		destroy(root);
	}
}

void DictionarySearchTree::destroy(TreeNode* ptr) {
	if (ptr != NULL) {
		destroy(ptr->leftChildPtr),
		destroy(ptr->rightChildPtr);
		delete ptr;
	}
}


void DictionarySearchTree::insert(string word) 
{
}


void DictionarySearchTree::search(string word, int& numComparisons, bool& found) const
{
	int comp = 0;
	found = searchNode(this->root, word,comp);
	numComparisons = comp;

}
void DictionarySearchTree::search(string queryFile, string outputFile) const {
	ifstream in;
	ofstream out;

	in.open(queryFile);
	out.open(outputFile);

	if (!(in && out)) {
		cout << "Unable the open file. Please check the path" << endl;
	}
	else {
		int queries = 0;
		int totalComp = 0;
		int maxComp = 0;
		string str;
		out << "Queries:   Found:    Comp:" << endl;
		while (getline(in, str)) {
			int comp = 0;
			bool found = 0;
			search(str, comp, found);

			if (found == 0) {
				comp = comp - 1;
			}

			string whitespace = "";
			for (int i = 0; i < 12 - str.length(); i++) {
				whitespace = whitespace + " ";
			}

			out << str << whitespace <<found<< "        " << comp << endl;

			queries = queries + 1;

			if (comp > maxComp) {
				maxComp = comp;
			}

			totalComp = totalComp + comp;

		}

		out << "# of queries: " << queries << endl;
		out << "Maximum # of comparisons: " << maxComp << endl;
		out << "Average # of comparisons: " << ((double)(totalComp)) / queries << endl;

		in.close();
		out.close();
	}
}

bool DictionarySearchTree::searchNode(TreeNode* ptr, string word, int& comp) const{
	comp = comp + 1;
	if (ptr == NULL) {
		return false;
	}
	else {
		if (ptr->item.compare(word) == 0) {
			return true;
		}
		else if(word.compare(ptr->item) > 0 ){
			return searchNode(ptr->rightChildPtr, word, comp);
		}
		else {
			return searchNode(ptr->leftChildPtr, word, comp);
		}
	}
}


void DictionarySearchTree::printInorder(TreeNode* node)
{
	if (node == NULL)
		return;


	/* then print the data of node */
	cout << node->item << " ";

	/* first recur on left child */
	printInorder(node->leftChildPtr);



	/* now recur on right child */
	printInorder(node->rightChildPtr);
}

