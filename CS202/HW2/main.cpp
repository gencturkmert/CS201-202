#include "BST.h"
#include <stdio.h>
#include "analysis.h"


int main() {
	BST* tree = new BST();

	int arr[10] = { 30, 40, 35,20, 50, 45, 10, 25, 5, 15 };

	for (int i = 0; i < 10; i++) {
		tree->insert(arr[i]);
	}

	std::cout << "Height: " << tree->getHeight() << std::endl;


	tree->deleteKey(35);
	tree->deleteKey(40);

	std::cout <<"Median: " << tree->medianOfBST() << std::endl;

	tree->rangeSearch(5, 43);

	std::cout << std::endl;

	heightAnalysis();

};