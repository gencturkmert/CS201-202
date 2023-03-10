#include "TreeNode.h"

TreeNode::TreeNode()
{
	item1 = -1;
	item2 = -1;
	item3 = -1;
	rb = -1;
	leftChildPtr = NULL;
	midLeftChildPtr = NULL;
	midRightChildPtr = NULL;
	rightChildPtr = NULL;
	id = -1;
	rep = "";
}

int TreeNode::size()
{
	if (isLeaf()) {
		return 1;
	}
	else {
		int sizeR = rightChildPtr->size();
		int sizeL = leftChildPtr->size();

		return 1 + ( (sizeR > sizeL) ? sizeR : sizeL);
	}
}

void TreeNode::create234Node(int left, int mid, int right) {
	item1 = left;
	item2 = mid;
	item3 = right;
	rb = 0;
}

string TreeNode::getRep()
{
	string rep = this->id + " " + to_string(this->item1) + " " + to_string(this->item2) + " " + to_string(this->item3)
		+ " " + (this->leftChildPtr != NULL ? to_string(this->leftChildPtr->id) : "-1") + " " + (this->midLeftChildPtr != NULL ? to_string(this->midLeftChildPtr->id) : "-1") + " " +
		(this->midRightChildPtr != NULL ? to_string(this->midRightChildPtr->id) : "-1") + " " + (this->rightChildPtr != NULL ? to_string(this->rightChildPtr->id) : "-1") + "\n";

	return rep;
}

bool TreeNode::isLeaf()
{
	if (leftChildPtr == NULL && midLeftChildPtr == NULL && midRightChildPtr == NULL && rightChildPtr == NULL) {
		return true;
	}
	else {
		return false;
	}
}

bool TreeNode::isFull()
{
	if (item1 != 0 && item2 != 0 && item3 != 0) {
		return true;
	}
	else {
		return false;
	}
}

void TreeNode::setRed()
{
	rb = 1;
}

void TreeNode::setBlack()
{
	rb = -1;
}

void TreeNode::setRedBlack(int rb)
{
	this->rb = rb;
}
