#include <iostream>
#include "TicTacToe.h"

using namespace std;

void main() {
	int currentRound = 0, currentPlayer;
	char currentPlayerChar, comma;
	std::array<std::array<char, 3>, 3> board = { 0 };
	for (currentRound; currentRound < 9; currentRound++) {
		if (currentRound % 2 == 0) {
			currentPlayer = 1;
			currentPlayerChar = 'X';
		}
		else {
			currentPlayer = -1;
			currentPlayerChar = 'O';
		}
		PrintBoard(board);
		int row, column;
		bool validMove = false;
		while (!validMove) {
			cout << currentPlayerChar << "'s turn: ";
			GetMove(&row, &column);
			validMove = MoveIsValid(board, row, column);
		}
		board[row][column] = currentPlayer;
	}
	PrintBoard(board);	
	return;
}
