#include "StackString.h"
#include <string>
using namespace std;


// default constructor

StackString::StackString() {
	StackString::top = -1;
}

bool StackString::isEmpty() const {

	return top < 0;

}

bool StackString::push(char newItem) {

	// if stack has no more room for 
	// another item
	if (top >= MAX_STACKSTRING - 1)
		return false;

	else {
		++top;
		items[top] = newItem;
		return true;
	}

}

bool StackString::pop() {

	if (isEmpty())
		return false;

	// stack is not empty; pop top
	else {
		--top;
		return true;
	}

}

bool StackString::pop(char& stackTop) {

	if (isEmpty())
		return false;

	// stack is not empty; retrieve top
	else {
		stackTop = items[top];
		--top;
		return true;
	}

}

bool StackString::getTop(char& stackTop)
const {

	if (isEmpty())
		return false;

	// stack is not empty; retrieve top
	else {
		stackTop = items[top];
		return true;
	}

}

char StackString::getTop() {
	if (isEmpty())
		return 0;

	// stack is not empty; retrieve top
	else {
		return items[top];

	}
}

