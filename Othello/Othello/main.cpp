#include <array>
#include <iostream>
#include "OthelloGame.h" 

using namespace std;

void main() {
	array<array<char, 8>, 8> board = { 0 };
	int row, column, turnCount = 0;
	char currChar;
	bool gameOngoing = true, lastTurnPassed = false;
	board[3][3] = -1;
	board[3][4] = 1;
	board[4][3] = 1;
	board[4][4] = -1;
	while (gameOngoing) {
		((turnCount % 2) == 0) ? (currChar = 'B') : (currChar = 'W');
		PrintBoard(board);
		cout << endl;
		cout << currChar << "'s Turn. Enter Move in (Row,Column) format : ";
		GetMove(row, column);
		while (!IsValidMove(board, row, column)) {
			cout << "That is not a valid move, Please Input a valid move : ";
			GetMove(row, column);
		}
		if (row == -1 && column == -1) {
			cout << "Turn passed!" << endl;
			if (lastTurnPassed) {
				break;
			}
			lastTurnPassed = true;
		}
		else {
			ApplyMove(board, row, column, currChar);
			lastTurnPassed = false;
		}
		turnCount++;
	}
	if (GetValue(board) > 0) {
		cout << "Black Wins!" << endl;
	}
	else if (GetValue(board) < 0) {
		cout << "White Wins!" << endl;
	}
	else {
		cout << "It's a tie!" << endl;
	}
}

