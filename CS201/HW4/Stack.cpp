#include "Stack.h"


// default constructor

Stack::Stack() {
		Stack::top = -1;
	}

	bool Stack::isEmpty() const {

		return top < 0;

	}

	bool Stack::push(double newItem) {

		// if stack has no more room for 
		// another item
		if (top >= MAX_STACK - 1)
			return false;

		else {
			++top;
			items[top] = newItem;
			return true;
		}

	}

	bool Stack::pop() {

		if (isEmpty())
			return false;

		// stack is not empty; pop top
		else {
			--top;
			return true;
		}

	}

	bool Stack::pop(double& stackTop) {

		if (isEmpty())
			return false;

		// stack is not empty; retrieve top
		else {
			stackTop = items[top];
			--top;
			return true;
		}

	}

	bool Stack::getTop(double& stackTop)
		const {

		if (isEmpty())
			return false;

		// stack is not empty; retrieve top
		else {
			stackTop = items[top];
			return true;
		}

	}

	double Stack::getTop() {
		if (isEmpty())
			return 0;

		// stack is not empty; retrieve top
		else {
			return items[top];

		}
	}

