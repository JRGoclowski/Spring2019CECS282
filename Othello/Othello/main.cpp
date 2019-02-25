#include <array>
#include <iostream>
#include "OthelloGame.h" 

using namespace std;

void main() {
	array<array<char, 8>, 8> board = { 0 };
	int row, column, turnCount = 0;
	char currentPlayer;
	board[3][3] = -1;
	board[3][4] = 1;
	board[4][3] = 1;
	board[4][4] = -1;
	while (true) {
		((turnCount % 2) == 0) ? (currentPlayer = 'B') : (currentPlayer = 'W');
		PrintBoard(board);
		cout << "Enter place";
		GetMove(row, column);
		//cout << IsValidMove(board, row, column);
		if (IsValidMove(board, row, column)) {
			ApplyMove(board, row, column, currentPlayer);
		}
		turnCount++;
	}
}

