//Mert Gençtürk 22003506
#include "PuzzleRow.h"
#include <iostream>
#include <string>
using namespace std;

PuzzleRow::PuzzleRow(int size,int index) {
	maxSize = size;
	rowindex = index;
	next = NULL;
	delete head;
	head = new PuzzlePiece();
	head->colindex = 1;
	head->rowindex = rowindex;
	head->shape = 0xff;
	delete head->next;
	head->next = new PuzzlePiece();
	PuzzlePiece* ptr = head->next;
	for (int i = 1; i < maxSize; i++) {
		ptr->colindex = i+1;
		ptr->rowindex = rowindex;
		ptr->shape = 0xff;
		if (i + 1 != maxSize) {
			delete ptr->next;
			ptr->next = new PuzzlePiece();
			ptr = ptr->next;
		}
		else {
			ptr->next = NULL;
		}
	}
}
PuzzleRow::~PuzzleRow() {
	PuzzlePiece* ptr = head;
	PuzzlePiece* next;
	while (ptr != NULL) {
		next = ptr->next;
		delete ptr;
		ptr = next;
	}

}

int PuzzleRow::getRowIndex()
{
	return rowindex;
}

void PuzzleRow::setNext(PuzzleRow* next)
{
	if (this->next != NULL) {
		next->next = this->next->next;
		this->next = next;
	}
	else {
		this->next = next;
	}
}

PuzzleRow* PuzzleRow::getNext()
{
	return next;
}

bool PuzzleRow::insert(int index, char shape)
{
	
		PuzzlePiece* ptr = head;
		for (int i = 1; i < index; i++) {
			ptr = ptr->next;
		}
		ptr->shape = shape;

		return true;
	
}

bool PuzzleRow::remove(int index)
{

		PuzzlePiece* ptr = head;
		for (int i = 1; i < index; i++) {
			ptr = ptr->next;
		}

		ptr->shape = 0xff;

		return true;
}

bool PuzzleRow::isEmpty()
{
	return false;
}

char PuzzleRow::getPiece(int index)
{
		PuzzlePiece* ptr = head;
		for (int i = 1; i < index; i++) {
			ptr = ptr->next;
		}
		return ptr->shape;
}

void PuzzleRow::printRow()
{
	cout << rowindex;
	for (int i = 1; i <= maxSize; i++) {
		//PuzzlePiece* ptr = head;
		if (getPiece(i) != -1)
			cout << "  " << "X";
		else
			cout << "  " << "O";
	}

	cout << endl;

}

void PuzzleRow::printShapes() {
	for (PuzzlePiece* ptr = head; ptr != NULL; ptr = ptr->next) {
		cout << "Shapes"<<ptr->shape+2 << endl;
	}
}
