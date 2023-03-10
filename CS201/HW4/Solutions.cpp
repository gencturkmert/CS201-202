#include <string>
#include "Stack.h"
#include <iostream>
#include "StackString.h"
#include "Solutions.h"
#include <cmath>

void subset(string intervals, int length)
{
	Stack st;
	int str_length = intervals.length();
	int* arr = new int[length];
	int index = 0;

	for (int i = 0; i < length; i++) {
		arr[i] = 0;
	}

	char current;
	char nextChar;
	for (int i = 0; i < str_length; i++) {
		if (intervals[i] != ',' && index < length) {
			current = intervals[i];
			nextChar = intervals[i + 1];
			if (nextChar != ',' && nextChar != '\0') {

				arr[index] = stoi(intervals.substr(i, i + 1));
				i++;
				index++;
			}
			else {
				arr[index] = (int)current - '0';
				index++;
			}
		}
	}



	for (int j = 0; j < length; j++) {
		st.push(arr[j]);
	}


	delete[] arr;
	double up1, up2, low1, low2;
	string out = "";
	while (!st.isEmpty()) {
		st.pop(up1);
		st.pop(low1);
		if (st.isEmpty()) {
			out = "(" + to_string((int)low1) + "," + to_string((int)up1) + ")" + out;

		}
		else {
			st.pop(up2);
			st.pop(low2);

			if (low1 <= up2) {
				st.push(low2);
				st.push(up1);
			}
			else {
				out = "(" + to_string((int)low1) + "," + to_string((int)up1) + ")" + out;

				st.push(low2);
				st.push(up2);
			}
		}

	}

	out = "Joined subset:" + out;
	cout << out << endl;


}

int importance(char x) {
	if (x == '^') {
		return 3;
	}
	else if (x == '*' || x == '/') {
		return 2;
	}
	else if (x == '+' || x == '-') {
		return 1;
	}
	else {
		return 0;
	}

}

string infix2prefix(string expression) {
	string reverse = "";
	for (int i = expression.length() - 1; i >= 0; i--) {
		reverse = reverse + expression[i];
	}

	StackString st;
	string out;
	char d;
	char pop;
	for (int i = 0; i <= reverse.length(); i++) {
		d = reverse[i];
		if (isdigit(d)) {
			out = d + out;
		}
		else {
			if (d == ')') {
				st.push(d);
			}
			else if (d == '(') {
				while (st.getTop() != ')') {
					st.pop(pop);
					out = pop + out;
				}

				st.pop();
			}


			else {
				if (d == '^') {
					while (importance(d) <= st.getTop()) {
						out = st.getTop() + out;
						st.pop();
					}
				}
				else {
					while (importance(d) < importance(st.getTop())) {
						st.pop(pop);
						out = pop + out;
					}
				}

				st.push(d);
			}
		}
	}

	while (!st.isEmpty()) {
		st.pop(pop);
		out = pop + out;
	}

	return out;

}

int evaluateOperator(char c, int a, int b) {
	int result;

	if (c == '+')
		result = a + b;
	else if (c == '-')
		result = a - b;
	else if (c == '*')
		result = a * b;
	else if (c == '/')
		result = a / b;
	else if (c == '^')
		result = pow(a, b);

	return result;
}
void evaluatePrefix(string expression) {
	Stack st;
	int count = expression.length() - 1;

	double a, b, res;
	string out = "";
	for (int i = count; i >= 0; i--) {
		char x = expression[i];

		if (isdigit(x)) {
			st.push((int)x - '0');
		}
		else {
			st.pop(a);
			st.pop(b);

			res = evaluateOperator(x, a, b);

			st.push(res);

		}
	}

	cout << "Result of " << expression << " is : " << st.getTop() << endl;;

}