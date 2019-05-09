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

	shared_ptr<GameBoard> board;
	unique_ptr<GameView> v;

	cout << "Which game would you like to play?" << endl;
	cout<< "1) Othello; 2) Tic Tac Toe; 3) Connect Four; 4) Exit;" << endl;
	int desiredGame;
	cin >> desiredGame;
	switch (desiredGame) {
		case 1: {
			auto oBoard = make_shared<OthelloBoard>();
			v = make_unique<OthelloView>(oBoard);
			board = oBoard;
			break;
		}
		case 2: {
			auto oBoard = make_shared<OthelloBoard>();
			v = make_unique<OthelloView>(oBoard);
			board = oBoard;
			break;
		}
		case 3: {
			auto oBoard = make_shared<OthelloBoard>();
			v = make_unique<OthelloView>(oBoard);
			board = oBoard;
			break;
		}
		case 4:
	}







	auto board = std::make_shared<OthelloBoard>(); // the state of the game board
	OthelloView v(board); // a View for outputting the board via operator<<
	string userInput, currPlay; // a string to hold the user's command choice
	bool isValidMove = false, continuePlaying = true, lastMovePass = false;
	do {
		isValidMove = false;
		cout << v << endl << "Possible Moves: " << endl;
	   	std::vector<unique_ptr<OthelloMove>> possibleMoves = board->GetPossibleMoves();
		for (auto moveWalker = possibleMoves.begin(); moveWalker != possibleMoves.end(); moveWalker++) {
			cout << **moveWalker << " ";
		}
		cout << endl << "[move (r, c)][undo n][showValue][showHistory][quit]" << endl << "Please input action:" ;
 		getline(cin, userInput);
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
				board->ApplyMove(std::move(v.ParseMove(userInput.substr(5, userInput.capacity()))));
			}
			else {
				cout << endl << "That was not a move option";
			}
			lastMovePass = false;
		}
		else if (userInput.substr(0, 4) == "undo") {
			int moveCount = board->GetMoveHistory().capacity();
			if ((stoi(userInput.substr(5, userInput.capacity())) <= moveCount)) {
				moveCount = (stoi(userInput.substr(5, userInput.capacity())));
			}
			for (int i = 0; i < moveCount; i++) {
				if (!(board->GetMoveHistory().empty())) {
					board->UndoLastMove();
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
	} while (continuePlaying);
	
}