#pragma once

#include "GameView.h"
#include "TicTacToeBoard.h"
#include "TicTacToeMove.h"


class TicTacToeView : public GameView {
private:
	std::shared_ptr<TicTacToeBoard> mTicTacToeBoard;

	void PrintBoard(std::ostream& s) const override;

public:
	
	TicTacToeView(std::shared_ptr<TicTacToeBoard> b) : mTicTacToeBoard(b) {
	}

	friend std::ostream& operator<< (std::ostream& os, const GameView& v) {
		v.PrintBoard(os);
		return os;
	}
		
	std::unique_ptr<GameMove> ParseMove(const std::string& move) const override;
		
	std::string GetPlayerString(int player) const override;
};
