//Mert Gençtürk 22003506
#ifndef PUZZLEROW_H
#define PUZZLEROW_H

class PuzzleRow {
private:
	struct PuzzlePiece {
		char shape;
		int rowindex;
		int colindex;
		PuzzlePiece* next;
	};
	PuzzlePiece* head;
	PuzzleRow* next;
	int rowindex;
	int maxSize; //equals to puzzleContainer width
public:
	PuzzleRow(int size, int rowindex);
	~PuzzleRow();
	int getRowIndex();
	void setNext(PuzzleRow* next);
	PuzzleRow* getNext();
	bool insert(int index, char shape);
	bool remove(int index);
	bool isEmpty();
	char getPiece(int index);
	void printRow();
	void printShapes();
};

#endif
