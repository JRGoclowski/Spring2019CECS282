#include "OthelloBoard.h"


OthelloBoard::OthelloBoard() :mBoard {Player::EMPTY} , mValue(0), mNextPlayer(Player::BLACK) {
	
	mBoard[(BOARD_SIZE / 2) - 1][(BOARD_SIZE / 2) - 1] = Player::WHITE ;
	mBoard[(BOARD_SIZE / 2) - 1][(BOARD_SIZE / 2)] = Player::BLACK;
	mBoard[(BOARD_SIZE / 2)][(BOARD_SIZE / 2) - 1] = Player::BLACK;
	mBoard[(BOARD_SIZE / 2)][(BOARD_SIZE / 2)] = Player::WHITE;
	mHistory.clear(); 
}


std::vector<std::unique_ptr<OthelloMove>> OthelloBoard::GetPossibleMoves() const {
	auto allPositions = BoardPosition::GetRectangularPositions(BOARD_SIZE, BOARD_SIZE);
	auto possibleMoves = std::vector<std::unique_ptr<OthelloMove>>();
	for (BoardPosition currentPos : allPositions) {
		if (GetPlayerAtPosition(currentPos) != Player::EMPTY) {
			continue;
		}
		for (BoardDirection currentDir : BoardDirection::CARDINAL_DIRECTIONS) {
			int flipCounter = 0;
			auto moveWalker = currentPos + currentDir;
			while (InBounds(moveWalker) && PositionIsEnemy(moveWalker, mNextPlayer)) {
				flipCounter++;
				moveWalker = moveWalker + currentDir;
			}
			if (InBounds(moveWalker) && flipCounter > 0) {
				if (GetPlayerAtPosition(moveWalker) == mNextPlayer) {
					possibleMoves.push_back(std::make_unique<OthelloMove>(currentPos));
				}
			}
		}
	}
	return possibleMoves;
}

/*			
			if (InBounds(moveWalker) || GetPlayerAtPosition(moveWalker) == mNextPlayer || flipCounter > 0) {
				possibleBoardPosition.push_back(currentPos);
			}
		}
	}
	auto possibleMoves = std::vector<std::unique_ptr<OthelloMove>>();
	for (BoardPosition backPosition : possibleBoardPosition){
		possibleMoves.push_back(std::move(std::make_unique<OthelloMove>(backPosition)));
	}
	return possibleMoves;*/

void OthelloBoard::ApplyMove(std::unique_ptr<OthelloMove> m) {
	for (BoardDirection currentDir : BoardDirection::CARDINAL_DIRECTIONS) {
		int flipCounter = 0;
		auto moveWalker = m->mPosition + currentDir;
		while (InBounds(moveWalker) && PositionIsEnemy(moveWalker, mNextPlayer)) {
			flipCounter++;
			moveWalker = moveWalker + currentDir;
		}
		if (!InBounds(moveWalker) || GetPlayerAtPosition(moveWalker) != mNextPlayer || flipCounter == 0) {
			continue;
		}
		auto applyWalker = m->mPosition;
		while (!(applyWalker + currentDir == moveWalker)) {
			applyWalker = applyWalker + currentDir;
			mBoard[applyWalker.getRow()][applyWalker.getColumn()] = mNextPlayer;
			mValue = mValue + 2*(static_cast <int> (mNextPlayer));
		}
		m->AddFlipSet(OthelloMove::FlipSet::FlipSet((char)flipCounter, currentDir));
	}
	mBoard[m->mPosition.getRow()][m->mPosition.getColumn()] = mNextPlayer;
	mValue = mValue + static_cast <int> (mNextPlayer);
	(mNextPlayer == Player::BLACK) ? (mNextPlayer = Player::WHITE) : (mNextPlayer = Player::BLACK);
	mHistory.push_back(std::move(m));
}

void OthelloBoard::UndoLastMove()
{
}
