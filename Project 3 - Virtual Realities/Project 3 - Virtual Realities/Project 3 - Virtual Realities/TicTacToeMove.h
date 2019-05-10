#pragma once

#include "GameMove.h"
#include "BoardPosition.h"


class TicTacToeMove: public GameMove {
private: 
	BoardPosition mPosition;

	friend class TicTacToeBoard;

public:
	TicTacToeMove(BoardPosition p) : mPosition(p) {
	}

	operator std::string() const override;

	bool operator==(const GameMove& rhs) const override;
};
