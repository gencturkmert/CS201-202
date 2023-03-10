/**
* Title : Binary Search Trees
* Author : Mert Gençtürk
* ID: 22003506
* Section : 1
* Assignment : 2
* Description : Analysis function & shuffle function
*/
#include "analysis.h"


void heightAnalysis() {

	BST* bst = new BST();

	int* arrAll = new int[100000];

	for (int j = 0; j < 100000; j++) {
		arrAll[j] = j;
	}

	shuffle(arrAll,100000);

	int* arr = new int[30000];

	std::cout << "Part f - Analysis of BST height - part 1" << std::endl;
	std::cout << "Tree Size        Tree Height       Size" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;

	for (int i = 0; i < 30000; i++) {

		arr[i] = arrAll[i];
		bst->insert(arr[i]);

		if (i % 1500 == 1499) {
			std::cout << i+1 << "             ";
			std::cout<<bst->getHeight()<< "             ";
			std::cout << bst->size << std::endl;

		}
	}

	std::cout << "------------------------------------------------" <<std::endl;
	std::cout << "Part f - Analysis of BST height - part 2" << std::endl;
	std::cout << "Tree Size        Tree Height" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;

	shuffle(arr, 30000);

	for (int i = 0; i < 30000; i++) {
		bst->deleteKey(arr[i]);


		if (i % 1500 == 1499) {
			std::cout << 30000 -( i+1) << "             ";
			std::cout << bst->getHeight() << "             ";
			std::cout << bst->size << std::endl;
		}
	}

}


void shuffle(int* arr,int size) {

	for (int i = size-1; i>0 ; i--) {
		int tmp = arr[i];
		int j = rand() % (i + 1);
		arr[i] = arr[j];
		arr[j] = tmp;
	}
}


