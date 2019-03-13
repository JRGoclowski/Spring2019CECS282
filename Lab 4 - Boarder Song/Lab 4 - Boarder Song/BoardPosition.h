#pragma once
#include "BoardDirection.h"
#include <ostream>;
#include <istream>;
#include <vector>;

class BoardPosition {

private:
	
	char mRow, mColumn;

	bool InBounds(int boardSize);

	bool InBounds(char rows, char columns);

public: 

	BoardPosition(const char& row, const char& column);
	
	inline char& const getRow() { return mRow; }

	inline char& const getColumn() { return mColumn; }

	operator std::string() const;

	friend std::istream& operator>>(std::istream &lhs, BoardPosition& rhs);

	bool operator==(BoardPosition rhs);

	bool operator<(BoardPosition rhs);

	BoardPosition operator+(BoardDirection dir);

	static std::vector<BoardPosition> GetRectangularPositions(char rows, char columns);//TODO confused as to what this does
};

std::ostream& operator<< (std::ostream &lhs, BoardPosition rhs);