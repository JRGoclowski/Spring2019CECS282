#include <array>
#include <iostream>

using namespace std;

// PrintBoard takes a 2-dimensional array parameter representing the game state
// and prints it to cout. See the spec for details on formatting the output.
void PrintBoard(std::array<std::array<char, 3>, 3> board) {
	int charAt;
	std::array <char, 4> title= { '-', '0', '1', '2' };
	for (int row = 0; row < 4; row++) {
		if (row == 0) {
			for (int column = 0; column < 4; column++) {
				cout << title[column];
			}
		}
		else {
			cout << title[row];
			for (int column = 0; column < 3; column++) {
				charAt = board[row - 1][column]; //Must be row - 1 because of extra row added by first line
				if (charAt == 0) {
					cout << '.';
				}
				else if (charAt == 1) {
					cout << 'X';
				}
				else if (charAt == -1) {//Can also be an else statement
					cout << 'O';
				}
			}
		}
		cout << endl;
	}

}


// GetMove uses cin to read the user's choice for where to move next on the 
// board. It does NOT update the game board with the move choice; it simply
// scans in values to the row and col variables, which will update whatever
// variables were used as arguments in the main. Do not check move validity
// in this function.
void GetMove(int *row, int *col) {
	char comma;
	cin >> *row >> comma >>  *col;
	return;
}


// MoveIsValid returns true if the board is empty at the requested row/col,
// and false otherwise. Used in main to see if the move is valid and alert
// the user if it is not.
bool MoveIsValid(const std::array<std::array<char, 3>, 3> &board, int row, int col) {
	if (row > 2 || col > 2 || row < 0 || col < 0) {
		cout << "That space is outside of board range!" << endl;
		return false;
	}
	else if (board[row][col] != 0) {
		cout << "That space is already taken!" << endl;
		return false;
	}
	else {
		return true;
	}

}
