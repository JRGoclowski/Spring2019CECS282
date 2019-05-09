#pragma once

#include "GameView.h"

class TicTacToeView : public GameView {
private:

	virtual void PrintBoard(std::ostream& s) const = 0;

public:
	
	friend std::ostream& operator<< (std::ostream& os, const GameView& v) {
		v.PrintBoard(os);
		return os;
	}
		
	std::unique_ptr<GameMove> ParseMove(const std::string& move) const override;
		
	std::string GetPlayerString(int player) const override;
};
