#include "Tree234.h"
#include "RBTree.h"

#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;
int main(int argc, char** args) {

	string input = args[1];
	string output = args[2];

	ifstream file;
	file.open(input);
	// Check if the file was opened successfully
	if (!file.is_open()) {
		cerr << "Error: Unable to open file" << endl;
		return 1;
	}

	// Read the number of nodes and root node id from the first line
	int numNodes, rootNodeId;
	file >> numNodes >> rootNodeId;

	int** nodes = new int* [numNodes];

	for (int i = 0; i < numNodes; i++) {

		// Declare a memory block
		// of size n
		nodes[i] = new int[4];
	}


	// Read the information about each node and store it in the 2D array
	for (int i = 0; i < numNodes; i++) {
		file >> nodes[i][0] >> nodes[i][1] >> nodes[i][2] >> nodes[i][3];
	}

	// Close the file
	file.close();

	Tree234* tree = new Tree234();
	int key, leftK = -1, rightK = -1;
	//Find the root
	for (int i = 0; i < numNodes; i++) {
		if (nodes[i][0] == rootNodeId) {
			TreeNode* root = new TreeNode();

			int left = nodes[i][1];
			int right = nodes[i][2];

			for (int j = 0; j < numNodes; j++) {
				if (nodes[j][0] == left) {
					//left is red
					if (nodes[j][3] == 0) {
						leftK = nodes[i][1];
					}
				}if (nodes[j][0] == right) {
					if (nodes[j][3] == 0) {
						rightK = nodes[i][2];
					}
				}
			}

			root->create234Node(leftK, rootNodeId, rightK);
			tree->insert(root);

			break;

		}
	}

	for (int i = 0; i < numNodes; i++) {
		int midK = -1;
		int leftK = -1;
		int rightK = -1;
		//Node is black
		if (nodes[i][3] == 1 && nodes[i][0] != rootNodeId) {
			midK = nodes[i][0];

			for (int k = 0; k < numNodes; k = k + 1) {
				//Left
				if (nodes[k][0] == nodes[i][1]) {
					//Node is red
					if (nodes[k][3] == 0) {
						leftK = nodes[k][0];
					}
				}

				//Right
				if (nodes[k][0] == nodes[i][2]) {

					//Node is red
					if (nodes[k][3] == 0) {
						rightK = nodes[k][0];
					}
				}
			}

			TreeNode* newNode = new TreeNode();
			newNode->create234Node(leftK, midK, rightK);

			tree->insert(newNode);
		}

	}

	int no = tree->assignIds();

	ofstream out;
	out.open(output);

	if (!out.is_open()) {
		cout << "Error. Output file couldn't created" << endl;
		return 1;
	}

	out << no << " " << "0" << endl;

	out << tree->traverse() << endl;

	out.close();
	
};