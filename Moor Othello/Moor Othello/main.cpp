#include "OthelloBoard.h"
#include "OthelloView.h"
#include "OthelloMove.h"
#include "BoardPosition.h"
#include "BoardDirection.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

using namespace std;

int main(int argc, char* argv[]) {
	// Initialization
	auto board = std::make_shared<OthelloBoard>(); // the state of the game board
	OthelloView v(board); // a View for outputting the board via operator<<
	string userInput; // a string to hold the user's command choice
	bool continuePlaying = true;
	
	// Main loop
	//do {
		// Print the game board using the OthelloView object
		cout << v << endl;
	   // Print all possible moves
		std::vector<unique_ptr<OthelloMove>> possibleMoves = board->GetPossibleMoves();
		
		for (auto moveWalker = possibleMoves.begin(); moveWalker != possibleMoves.end(); moveWalker++) {
			cout << **moveWalker << " ";
		}
	   // Ask to input a command
		cout << "Please input desired action:" << endl << " [Move (r, c)][Undo n][showValue][showHistory][Quit]";
		cin >> userInput;
	   // Command loop:
		switch (toupper(userInput[0])) {//TODO check code past here
			case 'M':
				board->ApplyMove(std::move(v.ParseMove(userInput.substr(5, 6))));
				break;
			case 'U':
				for (int i = 0; i < (int)userInput[6]; i++) {
					board->UndoLastMove();
				}
				break;
			case 'S':
				switch (toupper(userInput[4])) {
				case 'V': 
					cout << "The current board value is " << board->GetValue();
					break;
				case 'H':
					vector<std::unique_ptr<OthelloMove>> hist = board->GetMoveHistory();
					for(vector<std::unique_ptr<OthelloMove>>::iterator endItr = hist.end(); endItr != hist.begin(); endItr--) {
						cout << endl << string(**endItr);
					}
					break;
				}
			case 'Q':
				continuePlaying = false;
				break;
		default:
			break;
		}
		  // move (r,c)
		  // undo n
		  // showValue
		  // showHistory
		  // quit
		
	} while (continuePlaying); // you may want to change the condition
	
}