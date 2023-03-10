#ifndef STACK_H
#define STACK_H
const int MAX_STACK = 10001;

//ADT Stack class from textbook & slides
class Stack {

public:
	Stack();

	bool isEmpty() const;
	bool push(double newItem);
	bool pop();
	bool pop(double& stackTop);
	bool getTop(double& stackTop) const;

	//Additional getTop function
	double getTop();

private:
	// array of stack items
	double items[MAX_STACK];
	// index to top of stack
	int top;
};

#endif 
