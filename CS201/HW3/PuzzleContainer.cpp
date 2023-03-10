//Mert Gençtürk 22003506
#include <iostream>
#include <string>
#include "PuzzleContainer.h"

using namespace std;

PuzzleContainer::PuzzleContainer(int h, int w)
{
	height = h;
	width = w;
	
	rowLists = new PuzzleRow(w,1);
	
	rowLists->setNext(new PuzzleRow(w, 2));
	PuzzleRow* ptr = rowLists->getNext();
	for(int i = 3; i <= height; i++) {
		ptr->setNext(new PuzzleRow(w, i));

		ptr = ptr->getNext();
	}
}

PuzzleContainer::~PuzzleContainer()
{
	PuzzleRow* ptr = rowLists;
	PuzzleRow* next;
	while (ptr != NULL) {
		next = ptr->getNext();
		delete ptr;
		ptr = next;
	}
}

PuzzleRow* PuzzleContainer::getRow(int index)
{
	PuzzleRow* ptr = rowLists;
	for (int i = 1; i < index; i++) {
		ptr = ptr->getNext();
	}

	return ptr;
}

bool PuzzleContainer::insertRow(int index)
{
	PuzzleRow* ptr = rowLists;
	for (int i = 1; i < index-1; i++) {
		ptr = ptr->getNext();
	}

	PuzzleRow* newRow = new PuzzleRow(width, index);
	newRow->setNext(ptr->getNext()->getNext());
	ptr->setNext(newRow);
	return true;

}

bool PuzzleContainer::removeRow(int index)
{
	PuzzleRow* ptr = rowLists;
	for (int i = 1; i < index - 1; i++) {
		ptr = ptr->getNext();
	}

	ptr->setNext(ptr->getNext()->getNext());

	delete ptr->getNext();

	return true;
}

bool PuzzleContainer::addPiece(int row, int col, char shape)
{
	if (row > height || row == 0 || col > width || col == 0) {
		cout << "("<< row << "," << col << ") is out of frame, it cannot be added" << endl;
		return false;
	}
	else {

		PuzzleRow* ptr = rowLists;
		for (int i = 1; i < row;i++) {
			ptr = ptr->getNext();
		}


		if (ptr->getPiece(col) != -1) {
			cout << "(" << row << "," << col << ") has been already occupied, it cannot be added" << endl;
			return false;
		}
		else {
			int upS = 3, downS = 3, rightS = 3, leftS = 3;
			shapeConverter(shape, downS, upS, rightS, leftS);
			int count = 0;

			for (int i = 0; i < 4; i++) {
				int up = 3, down = 3, right = 3, left = 3;
				//Upper piece
				if (i == 0) {
					if (row != 1) {

						PuzzleRow* ptrU = rowLists;
						for (int i = 1; i < row-1; i++) {
							ptrU = ptrU->getNext();
						}
						char shape = ptrU->getPiece(col);
						if (shape != -1) {
							shapeConverter(shape, down, up, right, left);
						}
						if ((down == 1 && upS == 0) || (down == 0 && upS == 1) || (down == 2 && upS == 2) || (down == 3))
							count++;
					}
					else {
						if (upS == 2)
							count++;
					}
				}
				//left piece
				else if (i == 1) {
					if (col != 1) {

						char shape = ptr->getPiece(col - 1);

						if (shape != -1) {
							shapeConverter(shape, down, up, right, left);
						}
						if ((right == 1 && leftS == 0) || (right == 0 && leftS == 1) ||
							(right == 2 && leftS == 2) || (right == 3))
							count++;
					}
					else {
						if (leftS == 2)
							count++;
					}
				}
				//right piece
				else if (i == 2) {
					if (col != width) {

						char shape = ptr->getPiece(col + 1);
						if (shape != -1) {
							shapeConverter(shape, down, up, right, left);
						}
						if ((left == 1 && rightS == 0) || (left == 0 && rightS == 1) ||
							(left == 2 && right == 2) || (left == 3))
							count++;

					}
					else {
						if (rightS == 2)
							count++;
					}
				}
				//bottom piece
				else {
					if (row != height) {
						ptr = ptr->getNext();
						char shape = ptr->getPiece(col);
						if (shape != -1) {
							shapeConverter(shape, down, up, right, left);
						}
						if ((up == 1 && downS == 0) || (up == 0 && downS == 1) || (up == 2 && downS == 2) || (up == 3))
							count++;
					}
					else {
						if (downS == 2)
							count++;
					}
				}
			}

			if (count == 4) {

				PuzzleRow* ptrI = rowLists;
				for (int i = 1; i < row; i++) {
					ptrI = ptrI->getNext();
				}
				ptrI->insert(col, shape);
				cout << "A piece is added to (" << row << "," << col << ")" << endl;
				return true;
			}
			else {
				
				cout << "Shape doesn’t fit into (" << row << "," << col << "), it cannot be added" << endl;
				return false;
			}
		}
	}
}

bool PuzzleContainer::removePiece(int row, int col)
{
	PuzzleRow* ptr = rowLists;
	for (int i = 1; i < row; i++) {
		ptr = ptr->getNext();
	}
	if (row > height || row == 0 || col > width || col == 0) {
		cout << "(" << row << "," << col << ") is out of frame, it cannot be removed" << endl;
		return false;
	}else if (ptr->getPiece(col) == -1) {
		cout << "(" << row << "," << col << ") has been already empty, it cannot be removed" << endl;
		return false;
	}
	else {
		ptr->remove(col);
		cout << "The piece on (" << row << "," << col << ") is removed" << endl;
		return true;
	}
	
}

int PuzzleContainer::getHeight()
{
	return height;
}

int PuzzleContainer::getWidth()
{
	return width;
}

void PuzzleContainer::showPiece(int row, int col)
{
	PuzzleRow* ptr = rowLists;
	for (int i = 1; i < row; i++) {
		ptr = ptr->getNext();
	}

	if (row > height || row == 0 || col > width || col == 0) {
		cout << "(" << row << "," << col << ") is out of frame, it cannot be shown" << endl;
		}
	else if (ptr->getPiece(col) == -1) {
		cout << "(" << row << "," << col << ") has been already empty, it cannot be shown" << endl;
	}
	else {
		char shape = ptr->getPiece(col);
		int up, down, right, left;
		shapeConverter(shape, down, up, right, left);
		string arr[] = { "Hole","Knob","Border" };
		string sides[] = { "Down", "Up","Right","Left" };
		int shapes[] = { down,up,right,left };
		for (int i = 0; i < 4; i++) {
			cout << sides[i] << ": " << arr[shapes[i]] << endl;
		}
	}

}

void PuzzleContainer::displayContainer() {

	cout << " ";
	for (int i = 1; i <= width; i++) {
		cout << "  " << i;
	}
	cout << endl;
	PuzzleRow* ptr = rowLists;
	for (int i = 1; i <= height; i++) {
		ptr->printRow();
		ptr = ptr->getNext();
	}

}

void PuzzleContainer::showColumn(int col) 
{
	if (col <= width && col > 0) {
		cout << "Col " << col << ":" << endl;
		
		for (PuzzleRow* ptr = rowLists; ptr->getNext() != NULL; ptr=ptr->getNext()) {
			if (ptr->getPiece(col) != -1) {
				cout << "X" << endl;
			}
			else {
				cout << "O" << endl;
			}
			
		}
	}

	else {
		cout << "Column " << col << " is out of bounds" << endl;
	}
}

void PuzzleContainer::showRow(int row) 
{
	if (row <= height && row >0) {
		cout << "Row " << row << ":" << endl;
		PuzzleRow* ptr = rowLists;
		for (int i = 1; i < row; i++) {
			ptr = ptr->getNext();
		}
		ptr->printRow();
	}
	
	else {
		cout << "Row " << row << " is out of bounds" << endl;
	}
}

void PuzzleContainer::findPiece(char shape) 
{
	
	int count = 0;
	for (PuzzleRow* ptr = rowLists; ptr->getNext() != NULL; ptr = ptr ->getNext()) {
		for (int i = 1; i <= width; i++) {
			if (ptr->getPiece(i) == shape) {
				cout << "(" << ptr->getRowIndex() << "," << i << ") ,";
				count++;
			}
		}
	}

	if (count != 0) {
		cout << "contain the piece that has shape :" << endl;
	}
	else {
		cout << "There is no piece that has shape" << endl;
	}
	int up, down, right, left;
	shapeConverter(shape, down, up, right, left);
	string arr[] = { "Hole","Knob","Border" };
	string sides[] = { "Down", "Up","Right","Left" };
	int shapes[] = { down,up,right,left };
	for (int i = 0; i < 4; i++) {
		cout << sides[i] << ": " << arr[shapes[i]] << endl;
	}

}

void PuzzleContainer::shapeConverter(unsigned char shape, int& down, int& up, int& right, int& left)
{
	down = shape % 4;
	up = (shape / 4) % 4;
	right = (shape / 16) % 4;
	left = shape / 64;
}

