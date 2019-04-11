#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include "OthelloView.h"
#include "OthelloBoard.h"

using namespace std;

void OthelloView::PrintBoard(std::ostream & s) const {
	OthelloBoard::Player playerAt;
	std::array <char, 9> title = { '-', '0', '1', '2', '3', '4', '5', '6', '7' };
	for (int column = 0; column < 9; column++) {
		s << title[column];
	}
	s << endl;
	for (int row = 1; row < 9; row++) {
		s << title[row];
		for (int column = 0; column < 8; column++) {
			playerAt = mOthelloBoard->mBoard[row - 1][column];
			if (playerAt == OthelloBoard::Player::EMPTY) {
				s << '.';
			}
			else if (playerAt == OthelloBoard::Player::BLACK) {
				s << 'B';
			}
			else if (playerAt == OthelloBoard::Player::WHITE) {
				s << 'W';
			}
		}
		s << endl;
	}
}

std::unique_ptr<OthelloMove> OthelloView::ParseMove(const std::string & strFormat) {
	int sRow, sCol;
	char openParen, comma, closeParen;
	istringstream passedString(strFormat);
<<<<<<< HEAD
	passedString >> openParen >> sRow >> comma >> sCol >> closeParen;
	return std::move(make_unique<OthelloMove>(BoardPosition(sRow, sCol)));

=======
	passedString >> openParen >> sRow >> comma >> space >> sCol >> closeParen;
	return make_unique<OthelloMove>(BoardPosition(sRow, sCol));
>>>>>>> b4d5193de5c17bb4fdbb1d6c95ffe1ebcf930621
}

std::ostream & operator<<(std::ostream & lhs, const OthelloView & rhs) {
	rhs.PrintBoard(lhs);
	(rhs.mOthelloBoard->GetNextPlayer() == OthelloBoard::Player::BLACK) ? (lhs << "Black") : (lhs << "White");
	return lhs << "'s Move";
}

std::ostream & operator<<(std::ostream & lhs, const OthelloMove & rhs) {
	return lhs << string(rhs);
}
