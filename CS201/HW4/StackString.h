

#define STACKSTRING_H

#include <string>
using namespace std;

const int MAX_STACKSTRING = 10001;

//ADT Stack class from textbook & slides
class StackString {

public:
	StackString();

	bool isEmpty() const;
	bool push(char newItem);
	bool pop();
	bool pop(char& stackTop);
	bool getTop(char& stackTop) const;

	//Additional getTop function
	char getTop();

private:
	// array of stack items
	char items[MAX_STACKSTRING];
	// index to top of stack
	int top;
};


