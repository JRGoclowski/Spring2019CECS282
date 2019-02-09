#include <iostream>
#include "TicTacToe.h"

using namespace std;

void main() {
	int currentRound = 0, currentPlayer;
	std::array<std::array<char, 3>, 3> board = { 0 };
	for (currentRound; currentRound < 9; currentRound++) {
		if (currentRound % 2 == 0) {
			currentPlayer = 1;
		}
		else {
			currentPlayer = -1;
		}

	}


	
	return;
}
