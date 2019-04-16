# include "OthelloMove.h"
# include <ostream>
# include <sstream>


bool OthelloMove::operator==(const OthelloMove & rhs) {
	return ((mPosition.getColumn() == rhs.mPosition.getColumn()) && (mPosition.getRow() == rhs.mPosition.getRow()));
}

// TODO check this is the correct format
OthelloMove::operator std::string() const {
	std::ostringstream moveStr;
	moveStr << "(" << (int) mPosition.getRow() << "," << (int) mPosition.getColumn() << ")";
	return moveStr.str();
}