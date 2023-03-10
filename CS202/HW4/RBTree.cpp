#include "RbTree.h"

RBTree::RBTree()
{
	root = NULL;
}

void RBTree::insertItem(TreeNode*& ptr, int item,int rb)
{
	if (ptr == NULL) {
		ptr = new TreeNode();
		ptr->item1 = item;
		ptr->rb = rb;
	}

	if (ptr->item1 > item) {
		insertItem(ptr->leftChildPtr, item, rb);
	}
	else {
		insertItem(ptr->rightChildPtr, item, rb);
	}


}

void RBTree::insert(int item,int rb)
{
	insertItem(root, item,rb);
}

void RBTree::inorder(TreeNode*& ptr) {
	
	if (ptr != NULL) {

		inorder(ptr->leftChildPtr);

		cout << ptr->item1 << "\n";

		inorder(ptr->rightChildPtr);

	}
}

void RBTree::inorder() {
	inorder(root);
}