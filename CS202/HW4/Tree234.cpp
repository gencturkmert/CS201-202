#include "Tree234.h"

Tree234::Tree234()
{
	root = NULL;
}

TreeNode* Tree234::insertItem(TreeNode*& ptr, int item)
{
	//Not needed
	return NULL;
}

void Tree234::insert(int item)
{
	TreeNode* ptr = insertItem(root,item);
	root = ptr;
}

void Tree234::inorder()
{
	inorder(root);
}

void Tree234::inorder(TreeNode*& ptr)
{
	if (ptr != NULL) {

		inorder(ptr->leftChildPtr);

		cout << ptr->item1 << "\n";

		inorder(ptr->midLeftChildPtr);

		if (ptr->item2 !=-1) {
			
			cout << ptr->item2 << "\n";
			
			inorder(ptr->midRightChildPtr);

			if (ptr->item3 != -1) {

				cout << ptr->item3 << "\n";
				inorder(ptr->rightChildPtr);
			}
		}


	}
}

void Tree234::insert(TreeNode*& newNode)
{
	insert(newNode, root);
}

void Tree234::insert(TreeNode*& newNode, TreeNode*& ptr)
{
	if (ptr == NULL) {
		ptr = newNode;
	}
	else {
		if (ptr->item2 < newNode->item2) {

			if (ptr->item3 != -1 && ptr->item3 < newNode->item2) {
				insert(newNode, ptr->rightChildPtr);
			}
			else {
				insert(newNode,ptr->midRightChildPtr);
			}
			
		}
		else {
			if (ptr->item1 != -1 && ptr->item1 > newNode->item2) {
				insert(newNode, ptr->leftChildPtr);
			}
			else {
				insert(newNode, ptr->midLeftChildPtr);
			}
		}
	}
}

void Tree234::assignIds(int& id,TreeNode*& ptr)
{
	if (ptr != NULL) {

		if (ptr->leftChildPtr != NULL) {
			id = id + 1;
			ptr->leftChildPtr->id = id;
		}

		if (ptr->midLeftChildPtr != NULL) {
			id = id + 1;
			ptr->midLeftChildPtr->id = id;
		}

		if (ptr->midRightChildPtr != NULL) {
			id = id + 1;
			ptr->midRightChildPtr->id = id;
		}

		if (ptr->rightChildPtr != NULL) {
			id = id + 1;
			ptr->rightChildPtr->id = id;
		}

		assignIds(id, ptr->leftChildPtr);
		assignIds(id,ptr->midLeftChildPtr);
		assignIds(id,ptr->midRightChildPtr);
		assignIds(id,ptr->rightChildPtr);

	}
}

int Tree234::assignIds()
{	
	int id = 0;
	root->id = id;
	assignIds(id, root);

	return id;
}

string Tree234::traverse()
{
	string str = root->getRep();

	str = str + traverse(root);

	return str;
}

string Tree234::traverse(TreeNode*& ptr)
{
	if (ptr != NULL) {
		string str = "";

		if (ptr->leftChildPtr != NULL) {
			str = str + ptr->leftChildPtr->getRep();
		}

		if (ptr->midLeftChildPtr != NULL) {
			str = str + ptr->midLeftChildPtr->getRep();
		}
		if (ptr->midRightChildPtr != NULL) {
			str = str + ptr->midRightChildPtr->getRep();
		}

		if (ptr->rightChildPtr != NULL) {
			str = str + ptr->rightChildPtr->getRep();
		}

		str = str + traverse(ptr->leftChildPtr);
		str = str + traverse(ptr->midLeftChildPtr);
		str = str + traverse(ptr->midRightChildPtr);
		str = str + traverse(ptr->rightChildPtr);

		return str;


	}
	else {
		return "";
	}
}
