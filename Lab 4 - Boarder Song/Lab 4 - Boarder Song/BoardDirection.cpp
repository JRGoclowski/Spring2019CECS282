#include "BoardDirection.h"

BoardDirection::BoardDirection() : mRowChange(0), mColumnChange(0) {
}

BoardDirection::BoardDirection(const char & rowChange, const char & columnChange)
	: mRowChange(rowChange), mColumnChange(columnChange) {
}

inline const char & BoardDirection::getRowChange() {
	return mRowChange;
}

inline const char & BoardDirection::getColumnChange()
{
	return mColumnChange;
}
