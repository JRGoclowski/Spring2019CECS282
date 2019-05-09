#pragma once
 
#include "BoardPosition.h"
#include "GameBoard.h"


/*
Represents the state of a game board, with methods to query and manipulate that state
to support a game-agnostic main application.
*/
class TicTacToeBoard : public GameBoard {
public:
	
	std::vector<std::unique_ptr<GameMove>> GetPossibleMoves() const override;

	void ApplyMove(std::unique_ptr<GameMove> move) override;

	void UndoLastMove() override;

	bool IsFinished() const override;

	int GetValue() const override;

	int GetCurrentPlayer() const override;

	const std::vector<std::unique_ptr<GameMove>>& GetMoveHistory() const override;

};
