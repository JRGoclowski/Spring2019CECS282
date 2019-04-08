#include "OthelloBoard.h"


OthelloBoard::OthelloBoard(): mValue(0), mNextPlayer(Player::BLACK) {
	mBoard[(BOARD_SIZE / 2) - 1][(BOARD_SIZE / 2) - 1] = Player::WHITE ;
	mBoard[(BOARD_SIZE / 2) - 1][(BOARD_SIZE / 2)] = Player::BLACK;
	mBoard[(BOARD_SIZE / 2)][(BOARD_SIZE / 2) - 1] = Player::BLACK;
	mBoard[(BOARD_SIZE / 2)][(BOARD_SIZE / 2)] = Player::WHITE;
	//mHistory.clear(); 
}

std::vector<std::unique_ptr<OthelloMove>> OthelloBoard::GetPossibleMoves() const {
	auto allPositions = BoardPosition::GetRectangularPositions(BOARD_SIZE, BOARD_SIZE);
	for (BoardPosition currentPos : allPositions) {
		for (BoardDirection currentDir : BoardDirection::CARDINAL_DIRECTIONS) {
			int flipCounter = 0;
			auto moveWalker = currentPos + currentDir;
			while (InBounds(moveWalker) && PositionIsEnemy(moveWalker, mNextPlayer)) {
				flipCounter++;
				moveWalker = moveWalker + currentDir;
			}
			if (!InBounds(moveWalker) || GetPlayerAtPosition(moveWalker) != mNextPlayer || flipCounter == 0) {
				continue;
			}
		}
	}
	return std::vector<std::unique_ptr<OthelloMove>>();
}

void OthelloBoard::ApplyMove(std::unique_ptr<OthelloMove> m) {
	for (BoardDirection currentDir : BoardDirection::CARDINAL_DIRECTIONS) {
		int flipCounter = 0;
		auto moveWalker = m->mPosition + currentDir;
		while (InBounds(moveWalker) && PositionIsEnemy(moveWalker, mNextPlayer) ) {
			flipCounter++;
			moveWalker = moveWalker + currentDir;
		}
		if (!InBounds(moveWalker) || GetPlayerAtPosition(moveWalker) != mNextPlayer || flipCounter == 0) {
			continue;
		}
		auto applyWalker = m->mPosition; //TODO check that this applies as expected
		mBoard[applyWalker.getRow()][applyWalker.getColumn()] = mNextPlayer;
		for (flipCounter; flipCounter >= 0; flipCounter--) {
			applyWalker = applyWalker + currentDir;
			mBoard[applyWalker.getRow()][applyWalker.getColumn()] = mNextPlayer;
		}
	}

}

void OthelloBoard::UndoLastMove()
{
}
