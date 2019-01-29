#include <iostream>
#include <random>

using namespace std;

int main() {
	random_device rd;

	default_random_engine engine(rd());

	uniform_int_distribution <int> range(1, 3);
	uniform_int_distribution <int> toss(1, 2);

	int winningDoor = range(engine);
	int playerChoice, doorReveal;
	bool doorOneWinner = false, doorTwoWinner = false, doorThreeWinner = false,
		playerChoseOne = false, playerChoseTwo = false, playerChoseThree = false;

	if (winningDoor == 1)
	{
		doorOneWinner = true;
	}
	else if (winningDoor == 2)
	{
		doorTwoWinner = true;
	}
	else
	{
		doorThreeWinner = true;
	}

	cout << "Please input the desired door : " << endl;

	cin >> playerChoice;

	cout << "You've chosen door " << playerChoice << endl;

	if (playerChoice != winningDoor)
	{

	}
	cout << "Lets reveal "
		return 0;
}