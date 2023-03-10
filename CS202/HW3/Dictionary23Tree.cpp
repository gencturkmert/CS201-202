#include "Dictionary23Tree.h"
/**
* Title: 23Tree
* Author: Mert Gençtürk
* ID: 22003506
* Section: 1
* Assignment: 3
* Description: Dictionary 23 Tree implementation
*/

Dictionary23Tree::Dictionary23Tree(string dictionaryFile)
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

Dictionary23Tree::~Dictionary23Tree()
{
	destroy(root);

}

TreeNode* Dictionary23Tree::insertItem(TreeNode*& ptr, string item, TreeNode* parent)
{
	if (ptr == NULL) {
		ptr = new TreeNode(item, NULL, NULL);
		if (ptr == NULL)
			throw ("TreeException: insert failed");


	}

	//LEAF
	if (ptr->leftChildPtr == NULL && ptr->rightChildPtr == NULL && ptr->middleChildPtr == NULL) {
		
		if (ptr->item.empty()) {
			ptr->item = item;
		}
		else if (ptr->item2.empty()) {
			if (ptr->item < item) {
				ptr->item2 = item;
			}
			else {
				ptr->item2 = ptr->item;
				ptr->item = item;
			}
		}
		else {
			// 3 item case

			//item > rightItem
			if (ptr->item2 < item) {
				ptr->midItem = ptr->item2;
				ptr->item2 = item;
			}

			//1<item<<2
			else if (ptr->item < item) {
				ptr->midItem = item;
			}
			else {
				ptr->midItem = ptr->item;
				ptr->item = item;
			}

			
		}

		
	}
	else {


		//Locate the node
		if (item < ptr->item) {
			insertItem(ptr->leftChildPtr, item, ptr);
		}
		else if (!ptr->item2.empty()) {
			if (item > ptr->item2) {
				insertItem(ptr->rightChildPtr, item, ptr);
			}
			else {
				insertItem(ptr->middleChildPtr, item, ptr);
			}
		}
		else {
			insertItem(ptr->middleChildPtr, item, ptr);

		}
	}


	//Split
	if (ptr->size() == 3) {
		splitAndMove(ptr, item,parent);
	}


}

void Dictionary23Tree::insert(string word)
{
	//insertItem(root, word,root);
}

void Dictionary23Tree::search(string word, int& numComparisons, bool& found) const
{
	int comp = 0;
	found = searchNode(this->root, word, comp);
	numComparisons = comp;
}

void Dictionary23Tree::search(string queryFile, string outputFile) const
{
	ifstream in;
	ofstream out;

	in.open(queryFile);
	out.open(outputFile);

	out << "Implementation of 23 Tree is not finished." << endl;

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

			out << str << whitespace << found << "        " << comp << endl;

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



TreeNode* Dictionary23Tree::splitAndMove(TreeNode*& ptr, string word,TreeNode* parent)
{
	if (ptr == root) {
		parent = new TreeNode();
	}
	
	TreeNode* n1 = new TreeNode();
	n1->item = ptr->item;
	TreeNode* n2 = new TreeNode();
	n2->item = ptr->item2;

	if (ptr == parent->leftChildPtr) {
		parent->leftChildPtr = n1;
		parent->tempChild = n2;
	}
	else if (ptr == parent->middleChildPtr) {
		parent->middleChildPtr = n2;
		parent->tempChild = n1;
	}
	else if(ptr==parent->rightChildPtr) {
		parent->tempChild = parent->middleChildPtr;
		parent->middleChildPtr = n1;
		parent->rightChildPtr = n2;
	}
	//ROOT
	else {
		parent->leftChildPtr = n1;
		parent->middleChildPtr = n2;
	}

	//NOT LEAF
	if (ptr->leftChildPtr != NULL || ptr->rightChildPtr != NULL || ptr->middleChildPtr == NULL) {
		n1->leftChildPtr = ptr->leftChildPtr;
		n1->middleChildPtr = ptr->tempChild;

		n2->leftChildPtr = ptr->middleChildPtr;
		n2->rightChildPtr = ptr->rightChildPtr;
	}

	parent->midItem = ptr->midItem;


	return parent;

}

void Dictionary23Tree::destroy(TreeNode* ptr)
{
	if (ptr != NULL) {
		destroy(ptr->leftChildPtr);
		destroy(ptr->middleChildPtr);
		destroy(ptr->rightChildPtr);
		delete ptr;
	}
}

bool Dictionary23Tree::searchNode(TreeNode* ptr, string word, int& comp) const
{
	comp = comp + 1;
	if (ptr == NULL) {
		return false;
	}
	else if (word == ptr->item || word == ptr->item2) {
		return true;
	}
	else {
		if (word < ptr->item) {
			searchNode(ptr->leftChildPtr, word, comp);
		}
		else if (word < ptr->item2) {
			searchNode(ptr->middleChildPtr, word, comp);
		}
		else {
			searchNode(ptr->rightChildPtr, word, comp);
		}
	}
}
