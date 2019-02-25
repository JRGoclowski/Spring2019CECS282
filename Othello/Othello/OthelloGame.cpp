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
	char otherPlayer;
	int xDirection, yDirection, xInitial = row, yInitial = col, xCurrent, yCurrent, spotCounter, playerInt, otherInt;
	(currentPlayer == 'B') ? (otherPlayer = 'W') : (otherPlayer = 'B');
	(currentPlayer == 'B') ? (playerInt = 1, otherInt = -1) : (playerInt = -1, otherInt = 1);
	for (int position = 0; position < 9; position++) {
		//Chose a direction
		xDirection = directions[(position / 3)];
		yDirection = directions[(position % 3)];
		//Start at r,c
		//Needs some while loop
		//Take a single step in the direction
		xCurrent = xInitial + xDirection;
		yCurrent = yInitial + yDirection;
		spotCounter = 0;
		//	(Continue while not one of three things - Ally, empty, or bounds)
		//	If you find an enemy piece
		while (InBounds(xCurrent,yCurrent) && board[xCurrent][yCurrent] == otherInt) {
				//Increase Counter and repeat
				spotCounter++;
				xCurrent += xDirection;
				yCurrent += yDirection;
		}
		//Why did you stop
		//	If out of bounds or blank square
		if (!InBounds(xCurrent, yCurrent) || board[xCurrent][yCurrent] == 0) {
			//	return to top and pick a new direction	
			continue;
		}
		//	If ally it is a valid flip
		//		if counter 0 = nothing to do, return to top
		if (spotCounter == 0) {
			continue;
		}
		//		if counter > 0 = walk back and flip
		//			take a step back
		//			change tile to currentPlayer
		//			repeat for counter
		for (spotCounter; spotCounter >= 0; spotCounter--) { //CHECK THIS AND SEE IF SETS INITAL SPACE CORRECTLY
			board[xCurrent][yCurrent] = playerInt;
			xCurrent -= xDirection; 
			yCurrent -= yDirection;
		}
		board[xCurrent][yCurrent] = playerInt;
		//			return to top
	}
}

int GetValue(const OthelloMatrix & board)
{
	int boardValue;
	for (int position = 0; position < 64; position++) {
		if (board[position / 8][position % 8] == 'B') { boardValue++; }
		else if (board[position / 8][position % 8] == 'W') { boardValue--; }
	}
	return boardValue;
}
