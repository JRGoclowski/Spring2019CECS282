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

std::string TicTacToeView::GetPlayerString(int player) const
{
	return std::string();
}
