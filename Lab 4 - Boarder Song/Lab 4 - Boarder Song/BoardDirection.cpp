#include "BoardDirection.h"
#include <array>
using namespace std;

BoardDirection::BoardDirection() : mRowChange(0), mColumnChange(0) {
	BoardDirection::CARDINAL_DIRECTIONS = { BoardDirection(-1,-1), BoardDirection(-1,0), 
	BoardDirection(-1,1), BoardDirection(0,-1), BoardDirection(0,1), BoardDirection(1,-1),
	BoardDirection(1,0), BoardDirection(1,1) };
}

BoardDirection::BoardDirection(const char & rowChange, const char & columnChange)
	: mRowChange(rowChange), mColumnChange(columnChange) {
	BoardDirection::CARDINAL_DIRECTIONS = { BoardDirection(-1,-1), BoardDirection(-1,0), 
	BoardDirection(-1,1), BoardDirection(0,-1), BoardDirection(0,1), BoardDirection(1,-1),
	BoardDirection(1,0), BoardDirection(1,1) };
}

inline const char & BoardDirection::getRowChange() {
	return mRowChange;
}

inline const char & BoardDirection::getColumnChange()
{
	return mColumnChange;
}

