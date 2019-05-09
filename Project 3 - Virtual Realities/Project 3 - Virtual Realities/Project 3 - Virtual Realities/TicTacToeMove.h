#pragma once

#include "GameMove.h"

class TicTacToeMove: public GameMove {
public:
	
	operator std::string() const override;

	bool operator==(const GameMove& rhs) const override;
};
