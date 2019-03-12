#include "BoardPosition.h"

#include <sstream>
#include <ostream>

using namespace std; //Follow up if this was allowed

BoardPosition::BoardPosition(const char& row, const char& column) : mRow(row), mColumn(column) {
}

bool BoardPosition::InBounds(int boardSize) {
	int row = (int)mRow, column = (int)mColumn;
	return (row < (boardSize - 1) && row > 0 && column < (boardSize - 1) && column > 0);
}

bool BoardPosition::InBounds(char rows, char columns){
	int row = (int)mRow, column = (int)mColumn, maxRow = (int)rows, maxColumn = (int)columns;
	return (row < (maxRow - 1) && row > 0 && column < (maxColumn - 1) && column > 0);
}

//Follow up : getters not necessary here, defined in header, correct?

BoardPosition::operator std::string() const {
	ostringstream boardPosStr;
	boardPosStr << "(" << mRow << ", " << mColumn << ")";
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
	return std::vector<BoardPosition>();
}

std::istream & operator>>(std::istream & lhs, BoardPosition & rhs) {
	// TODO: insert return statement here
}

std::ostream & operator<<(std::ostream & lhs, BoardPosition rhs) {
	// TODO: insert return statement here
}
