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
	auto board = std::make_shared<OthelloBoard>(); // the state of the game board
	OthelloView v(board); // a View for outputting the board via operator<<
	string userInput, currPlay; // a string to hold the user's command choice
	bool isValidMove = false, continuePlaying = true, lastMovePass = false;
	vector<std::string> testCase = {
		"move (2, 3)",
		"move (2, 2)",
		"move (3, 2)",
		"move (4, 2)",
		"move (3, 1)",
		"move (2, 1)",
		"move (1, 1)",
		"move (0, 0)",
		"showHistory",
		"move (0, 1)",
		"move (0, 2)",
		"move (4, 1)",
		"move (5, 1)",
		"move (1, 0)",
		"move (2, 0)",
		"move (3, 0)",
		"move (4, 0)",
		"move (5, 0)",
		"move (6, 0)",
		"move (6, 1)",
		"move (7, 1)",
		"move (5, 2)",
		"move (6, 5)",
		"move (6, 2)",
		"move (4, 5)",
		"move (5, 3)",
		"move (6, 3)",
		"move (5, 4)",
		"undo 1",
		"move (6, 4)",
		"move (7, 3)",
		"undo 2",
		"move (5, 4)",
		"move (6, 4)",
		"move (7, 3)",
		"move (7, 2)",
		"move (7, 4)",
		"move (7, 0)",
		"move (6, 5)",
		"move (1, 2)",
		"move (1, 3)",
		"move (1, 4)",
		"undo 1",
		"move (7, 5)",
		"move (5, 5)",
		"move (6, 6)",
		"move (6, 7)",
		"move (5, 6)",
		"move (7, 6)",
		"move (7, 7)",
		"move (3, 6)",
		"move (2, 7)",
		"move (2, 5)",
		"move (0, 3)",
		"move (0, 4)",
		"move (5, 7)",
		"move (1, 4)",
		"move (2, 4)",
		"move (1, 5)",
		"move (1, 6)",
		"move (2, 6)",
		"move pass",
		"move (0, 7)",
		"move (0, 5)",
		"move (0, 6)",
		"move pass",
		"move (4, 6)",
		"move (3, 5)",
		"move (3, 7)",
		"move (4, 7)",
		"move pass",
		"move (1, 7)",
		"showHistory",
		"showValue",
		"move pass",
		"move pass" };
	auto inputItr = testCase.begin();
	do {
		userInput = *inputItr;
		inputItr++;
		isValidMove = false;
		cout << v << endl << "Possible Moves: " << endl;
	   	std::vector<unique_ptr<OthelloMove>> possibleMoves = board->GetPossibleMoves();
		for (auto moveWalker = possibleMoves.begin(); moveWalker != possibleMoves.end(); moveWalker++) {
			cout << **moveWalker << " ";
		}
		cout << endl << "[move (r, c)][undo n][showValue][showHistory][quit]" << endl << "Please input action:" ;
 		//getline(cin, userInput);
		cout << "Debug statment: Input was " << userInput << endl << endl << endl;
		if (userInput.substr(0, 4) == "move") {
			if (userInput.substr(5, userInput.capacity()) == "pass") {
				board->ApplyMove(std::move(make_unique<OthelloMove>(BoardPosition(-1, -1))));
				if (lastMovePass == true) {
					continuePlaying = false;
				}
				lastMovePass = true;
				continue;
			}
			for (auto moveWalker = possibleMoves.begin(); moveWalker != possibleMoves.end(); moveWalker++) {
				if (userInput.substr(5, userInput.capacity()) == string(**moveWalker)) {
					isValidMove = true;
				}
			}
			if (isValidMove) {
				board->ApplyMove(std::move(v.ParseMove(userInput.substr(5, 6))));
			}
			else {
				cout << endl << "That was not a move option";
			}
			lastMovePass = false;
		}
		else if (userInput.substr(0, 4) == "undo") {
			if (!(board->GetMoveHistory().empty())) {
				if (!(stoi(userInput.substr(5, userInput.capacity())) >= board->GetMoveHistory().capacity())) {
					for (int i = 0; i < stoi(userInput.substr(5, userInput.capacity())); i++) {
						board->UndoLastMove();
					}
				}
				else {
					for (int i = 0; i < board->GetMoveHistory().capacity(); i++) {
						board->UndoLastMove();
					}
				}
			}
		}
		else if (userInput.substr(0, 4) == "show") {
			switch (toupper(userInput[4])) {
			case 'V':
				cout << "The current board value is " << board->GetValue() << endl;
				break;
			case 'H':
				auto lastItr = board->GetMoveHistory().rbegin();
				(board->GetNextPlayer() == OthelloBoard::Player::BLACK) ? (currPlay = "BLACK") : (currPlay = "WHITE");
				for (lastItr; lastItr != board->GetMoveHistory().rend(); lastItr++) {
					(currPlay == "WHITE") ? (currPlay = "BLACK") : (currPlay = "WHITE");
					cout << endl << currPlay << ": " << string(**lastItr) ;
				}
				break;
			}
		}
		else if (userInput.substr(0, 4) == "quit") {
				continuePlaying = false;
		}
		else {
			cout << endl << "That was not a valid input, please input a proper input";
		}
		cout << endl;
	} while (continuePlaying); // you may want to change the condition
	
}