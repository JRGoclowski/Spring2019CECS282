#pragma once
#include <ostream>;
#include <istream>;
#include <vector>;

operator std::string() const;

Global std::ostream& operator<< (std::ostream &lhs, BoardPosition rhs);

Friend std::istream& operator>>(std::istream &lhs, BoardPosition& rhs);

bool operator==(BoardPosition rhs);

bool operator<(BoardPosition rhs);

bool InBounds(int boardSize);

bool InBounds(int rows, int columns);

static std::vector<BoardPosition> GetRectangularPositions(int rows, int columns);