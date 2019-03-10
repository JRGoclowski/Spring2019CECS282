#include <array>
#include <iostream>
#include "OthelloGame.h" 

using namespace std;

void main() {
	array<array<char, BOARD_SIZE>, BOARD_SIZE> board = { 0 };
	int row, column, turnCount = 0;
	char currChar;
	bool gameOngoing = true, lastTurnPassed = false;
	board[(BOARD_SIZE / 2) - 1][(BOARD_SIZE / 2) - 1] = -1;
	board[(BOARD_SIZE / 2) - 1][(BOARD_SIZE / 2)] = 1;
	board[(BOARD_SIZE / 2)][(BOARD_SIZE / 2) - 1] = 1;
	board[(BOARD_SIZE / 2)][(BOARD_SIZE / 2)] = -1;
	while (gameOngoing) {
		((turnCount % 2) == 0) ? (currChar = 'B') : (currChar = 'W');
		PrintBoard(board);
		cout << endl << endl;
		cout << currChar << "'s Turn. Enter Move in (Row,Column) format : ";
		GetMove(row, column);
		while (!IsValidMove(board, row, column)) {
			cout << "That is not a valid move, Please Input a valid move : ";
			GetMove(row, column);
		}
		if (row == -1 && column == -1) {
			cout << "Turn passed!" << endl << endl;
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

