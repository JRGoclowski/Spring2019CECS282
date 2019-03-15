#include "BoardPosition.h"
#include "BoardDirection.h"
#include <iostream>

using namespace std;

int main() {
	BoardDirection testBD1 = BoardDirection(0, -1);
	BoardDirection testBD2 = BoardDirection(-1, -1);
	BoardPosition testBP1, testBP2;
	cin >> testBP1;
	testBP2 = BoardPosition(0, 2);
	//cin >> testBP2;
	//cout << (testBP1 == testBP2);
	cout << testBP1 << endl <<  testBP2;
	//testBP1 = testBP1 + testBD1;
	//cout << testBP1;
	//testBP1 = testBP1 + testBD2;
	//cout << testBP1;
	//cout << (testBP1 == testBP2);
	//cout << (testBP1 < testBP2);
}