#include "TicTacToeBoard.h"

std::vector<std::unique_ptr<GameMove>> TicTacToeBoard::GetPossibleMoves() const
{
	return std::vector<std::unique_ptr<GameMove>>();
}

void TicTacToeBoard::ApplyMove(std::unique_ptr<GameMove> move)
{
}

void TicTacToeBoard::UndoLastMove()
{
}

bool TicTacToeBoard::IsFinished() const
{
	return false;
}

int TicTacToeBoard::GetValue() const
{
	return 0;
}

int TicTacToeBoard::GetCurrentPlayer() const
{
	return 0;
}

const std::vector<std::unique_ptr<GameMove>>& TicTacToeBoard::GetMoveHistory() const
{
	// TODO: insert return statement here
}
