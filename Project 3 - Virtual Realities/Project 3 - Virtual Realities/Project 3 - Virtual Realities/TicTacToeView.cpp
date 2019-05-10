#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

#include "TicTacToeView.h"
#include "TicTacToeBoard.h"
#include "TicTacToeMove.h"

using namespace std;

std::unique_ptr<GameMove> TicTacToeView::ParseMove(const std::string& move) const {
	int sRow, sCol;
	char openParen, comma, closeParen;
	istringstream passedString(move);
	passedString >> openParen >> sRow >> comma >> sCol >> closeParen;
	return std::move(make_unique<TicTacToeMove>(BoardPosition(sRow, sCol)));
}

void TicTacToeView::PrintBoard(std::ostream& s) const {
	TicTacToeBoard::Player playerAt;
	std::array <char, 4> title = { '-', '0', '1', '2'};
	for (int column = 0; column < 4; column++) {
		s << title[column];
	}
	s << endl;
	for (int row = 1; row < 4; row++) {
		s << title[row];
		for (int column = 0; column < 8; column++) {
			playerAt = mTicTacToeBoard->mBoard[(row - 1)][column];
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

std::string TicTacToeView::GetPlayerString(int player) const {
	
	return std::string();
}
