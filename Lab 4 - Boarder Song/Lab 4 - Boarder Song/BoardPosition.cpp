#include "BoardPosition.h"
#include <string>
#include <sstream>
#include <ostream>

using namespace std; 

BoardPosition::BoardPosition() 
	: mRow(0), mColumn(0){
}

BoardPosition::BoardPosition(const char& row, const char& column) 
	: mRow(row), mColumn(column) {
}

bool BoardPosition::InBounds(int boardSize) {
	int row = (int)mRow, column = (int)mColumn;
	return (row < (boardSize - 1) && row > 0 && column < (boardSize - 1) && column > 0);
}

bool BoardPosition::InBounds(char rows, char columns){
	int row = (int)mRow, column = (int)mColumn, maxRow = (int)rows, maxColumn = (int)columns;
	return (row < (maxRow - 1) && row > 0 && column < (maxColumn - 1) && column > 0);
}


BoardPosition::operator std::string() const {
	ostringstream boardPosStr;
	if (mRow >= 48 || mColumn >= 48) {
		boardPosStr << "(" << mRow << ", " << mColumn << ")";
	}
	else {
		boardPosStr << "(" << (int)mRow << ", " << (int)mColumn << ")";
	}
	return boardPosStr.str();
}	

bool BoardPosition::operator==(BoardPosition rhs) {
	return (mRow == rhs.getRow() && mColumn == rhs.getColumn());
}

bool BoardPosition::operator<(BoardPosition rhs) {
	if ((int)mRow == (int)rhs.getRow()) {
		if ((int)mColumn < (int)rhs.getColumn()) {
			return true;
		}
	}
	return ((int)mRow < (int)rhs.getRow());
}

BoardPosition BoardPosition::operator+(BoardDirection dir) {
	int row = (int)mRow, col = (int)mColumn, rowDir = (int)dir.getRowChange(), colDir = (int)dir.getColumnChange();
	int newRow = row + rowDir , newCol = col + colDir;
	return BoardPosition((char)newRow, (char)newCol);
}

std::vector<BoardPosition> BoardPosition::GetRectangularPositions(char rows, char columns) {
	int rowInt = (int)rows, colInt = (int)columns;
	vector<BoardPosition> rectPositions;
	for (int i = 0; i < rowInt; i++) {
		for (int j = 0; j < colInt; j++) {
			rectPositions.push_back(BoardPosition((char)i, (char)j));
		}
	}
	return rectPositions;
}

std::istream & operator>>(std::istream & lhs, BoardPosition & rhs) {
	char frontParen, comma, endParen;
	lhs >> frontParen >> rhs.mRow >> comma >> rhs.mColumn >> endParen;
	return lhs;
	
}

std::ostream & operator<<(std::ostream & lhs, BoardPosition rhs) {
	return lhs << (string)rhs;
}
