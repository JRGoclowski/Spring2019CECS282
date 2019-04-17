#include "OthelloBoard.h"
#include "OthelloView.h"
#include "OthelloMove.h"
#include "BoardPosition.h"
#include "BoardDirection.h"
#include <iostream>
#include <istream>
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
	bool isValidMove = false, continuePlaying = true;
	
	// Main loop
	do {
		isValidMove = false;
		// Print the game board using the OthelloView object
		cout << v << endl << "Possible Moves: ";
	   // Print all possible moves
		std::vector<unique_ptr<OthelloMove>> possibleMoves = board->GetPossibleMoves();
		
		for (auto moveWalker = possibleMoves.begin(); moveWalker != possibleMoves.end(); moveWalker++) {
			cout << **moveWalker << " ";
		}
	   // Ask to input a command
		cout << endl << "[Move (r, c)][Undo n][showValue][showHistory][Quit]" << endl << "Please input action:" ;
		getline(cin, userInput);
		string chosenCommand = userInput.substr(0, 4);
	   // Command loop:
		if (chosenCommand == "Move") {
			char sixthChar = userInput[6], tenthChar = userInput[10];
			if (userInput[6] == '-' && userInput[10] == '-') {
				board->ApplyMove(std::move(make_unique<OthelloMove>(BoardPosition(-1, -1))));
				continue;
			}
			string testString = userInput.substr(5, 6);
			for (auto moveWalker = possibleMoves.begin(); moveWalker != possibleMoves.end(); moveWalker++) {
				bool conditionTest = testString/*userInput.substr(5, 6)*/ == string(**moveWalker);
				if (conditionTest) {
					isValidMove = true;
				}
			}
			if (isValidMove) {
				board->ApplyMove(std::move(v.ParseMove(userInput.substr(5, 6))));
			}
			else {
				cout << endl << "That was not a move option";
			}
		}
		else if (chosenCommand == "Undo") {
			for (int i = 0; i <= userInput[5]; i++) {
				board->UndoLastMove();
			}
		}
		else if (chosenCommand == "show") {
			switch (toupper(userInput[4])) {
			case 'V':
				cout << "The current board value is " << board->GetValue() << endl;
				break;
			case 'H'://TODO check this, doesn't work
				auto endItr = board->GetMoveHistory().end() - 1;
				auto beginItr = board->GetMoveHistory().begin();
				for (endItr; endItr != beginItr; --endItr) {
					cout << endl << string(**endItr);
				}
				cout << endl << string(**beginItr) << endl;
				break;
			}
		}
		else if (chosenCommand == "quit") { 
				continuePlaying = false;
		}
		else {
			cout << endl << "That was not a valid input, please input a proper input";
		}
		cout << endl;
		  // move (r,c)
		  // undo n
		  // showValue
		  // showHistory
		  // quit
		
	} while (continuePlaying); // you may want to change the condition
	
}