#include <array>
#include <iostream>
#include "OthelloGame.h"

using namespace std;

void PrintBoard(const OthelloMatrix & board) {
	int charAt;
	std::array <char, 9> title = { '-', '0', '1', '2', '3', '4', '5', '6', '7' };
	for (int column = 0; column < 9; column++) {
		cout << title[column];
	}
	for (int row = 1; row < 9; row++) {
		cout << endl;
		cout << title[row];
		for (int column = 0; column < 8; column++) {
			charAt = board[row - 1][column];
			if (charAt == 0) {
				cout << '.';
			}
			else if (charAt == 1) {
				cout << 'B';
			}
			else if (charAt == -1) {
				cout << 'W';
			}
		}
	}
}

bool InBounds(int row, int col) {
	if (row < 0 || row > 7 || col < 0 || col > 7) { return false; }
	return true;
}

bool IsValidMove(const OthelloMatrix & board, int row, int col) {
	if (row == -1 && col == -1) { return true; }
	else if (board[row][col] != 0) { return false; }
	else if (InBounds(row, col)) { return true; }

}

void GetMove(int & row, int & col) {
	char comma;
	cin >> row >> comma >> col;
}

void ApplyMove(OthelloMatrix & board, int row, int col, char currentPlayer) {
	array <int, 3> directions = { -1, 0, 1 };
	int xDirection, yDirection, xInitial = row, yInitial = col, xCurrent, yCurrent, spotCounter, currInt, oppInt;
	(currentPlayer == 'B') ? (currInt = 1, oppInt = -1) : (currInt = -1, oppInt = 1);
	for (int position = 0; position < 9; position++) {
		xDirection = directions[(position / 3)];
		yDirection = directions[(position % 3)];
		xCurrent = xInitial + xDirection;
		yCurrent = yInitial + yDirection;
		spotCounter = 0;
		while (InBounds(xCurrent,yCurrent) && board[xCurrent][yCurrent] == oppInt) {
				spotCounter++;
				xCurrent += xDirection;
				yCurrent += yDirection;
		}
		if (!InBounds(xCurrent, yCurrent) || board[xCurrent][yCurrent] == 0 || spotCounter == 0) {
			continue;
		}
		for (spotCounter; spotCounter >= 0; spotCounter--) { 
			board[xCurrent][yCurrent] = currInt;
			xCurrent -= xDirection; 
			yCurrent -= yDirection;
		}
		board[xCurrent][yCurrent] = currInt;
	}
}

int GetValue(const OthelloMatrix & board)
{
	int boardValue = 0;
	for (int position = 0; position < 64; position++) {
		if (board[position / 8][position % 8] == 1) { boardValue++; }
		else if (board[position / 8][position % 8] == -1) { boardValue--; }
	}
	return boardValue;
}
