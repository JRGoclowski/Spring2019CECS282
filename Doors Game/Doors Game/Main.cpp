#include <iostream>
#include <random>

using namespace std;

int main() {
	random_device rd;

	default_random_engine engine(rd());

	uniform_int_distribution <int> range(1, 3);
	uniform_int_distribution <int> toss(1, 2);
	uniform_int_distribution <int> win(1, 5);

	int winningDoor = range(engine);
	int coinToss = toss(engine);
	int prizeWon = win(engine);
	int playerChoice, doorReveal, playerChange;
	bool doorOneWinner = false, doorTwoWinner = false, doorThreeWinner = false,
		playerChoseOne = false, playerChoseTwo = false, playerChoseThree = false,
		doorOneRevealed = false, doorTwoRevealed = false, doorThreeRevealed = false,
		playerWon = false;

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

	cout << "Please input the desired door (1,2, or 3): " << endl;

	cin >> playerChoice;

	cout << "You've chosen door " << playerChoice << endl;

	if (playerChoice == 1)
	{
		playerChoseOne = true;
	}
	else if (playerChoice == 2)
	{
		playerChoseTwo = true;
	}
	else
	{
		playerChoseThree = true;
	}

	if (playerChoice == winningDoor)
	{
		if (playerChoseOne)
		{
			if (coinToss == 1)
			{
				cout << "Let's reveal what's behind door #2!" << endl;
				cout << "It's a goat!" << endl;
				doorTwoRevealed = true;
			}
			else
			{
				cout << "Let's reveal what's behind door #3!" << endl;
				cout << "It's a goat!" << endl;
				doorThreeRevealed = true;
			}
		}
		else if (playerChoseTwo)
		{
			if (coinToss == 1)
			{
				cout << "Let's reveal what's behind door #1!" << endl;
				cout << "It's a goat!" << endl;
				doorOneRevealed = true;
			}
			else
			{
				cout << "Let's reveal what's behind door #3!" << endl;
				cout << "It's a goat!" << endl;
				doorThreeRevealed = true;
			}
		}
		else
		{
			if (coinToss == 1)
			{
				cout << "Let's reveal what's behind door #1!" << endl;
				cout << "It's a goat!" << endl;
				doorOneRevealed = true;
			}
			else
			{
				cout << "Let's reveal what's behind door #2!" << endl;
				cout << "It's a goat!" << endl;
				doorTwoRevealed = true;
			}
		}
	}
	else
	{
		if (playerChoseOne)
		{
			if (doorTwoWinner)
			{
				cout << "Let's reveal what's behind door #3!" << endl;
				cout << "It's a goat!" << endl;
				doorThreeRevealed = true;
			}
			else
			{
				cout << "Let's reveal what's behind door #2!" << endl;
				cout << "It's a goat!" << endl;
				doorTwoRevealed = true;
			}
		}
		else if (playerChoseTwo)
		{
			if (doorOneWinner)
			{
				cout << "Let's reveal what's behind door #3!" << endl;
				cout << "It's a goat!" << endl;
				doorThreeRevealed = true;
			}
			else
			{
				cout << "Let's reveal what's behind door #1!" << endl;
				cout << "It's a goat!" << endl;
				doorOneRevealed = true;
			}
		}
		else
		{
			if (doorOneWinner)
			{
				cout << "Let's reveal what's behind door #2!" << endl;
				cout << "It's a goat!" << endl;
				doorTwoRevealed = true;
			}
			else
			{
				cout << "Let's reveal what's behind door #1!" << endl;
				cout << "It's a goat!" << endl;
				doorOneRevealed = true;
			}
		}
	}

	cout << "Would you like to keep your door, or change it? (0 to Keep, 1 to Change)" << endl;
	cin >> playerChange;
	if (playerChange)
	{
		if (playerChoseOne)
		{
			if (doorTwoRevealed)
			{
				playerChoice = 3;
			}
			else
			{
				playerChoice = 2;
			}
		}
		else if (playerChoseTwo)
		{
			if (doorOneRevealed)
			{
				playerChoice = 3;
			}
			else
			{
				playerChoice = 1;
			}
		}
		else
		{
			if (doorOneRevealed)
			{
				playerChoice = 2;
			}
			else
			{
				playerChoice = 1;
			}
		}

	}
	else
	{
		playerChoice = playerChoice;
	}
	
	if (playerChoice == winningDoor)
	{
		playerWon = true;
	}
	cout << "Your final door is door #" << playerChoice << endl;
	cout << "Well lets see what you have behind your door!" << endl;
	if (playerWon)
	{
		if (prizeWon == 1)
		{
			cout << "CONGRATULATIONS! You're now the proud owner of your very own tiger cyborg butler!" << endl;
			cout << "I heard they're great with cooking, but not so great with kids. Enjoy!" << endl;
		}
		else if (prizeWon == 2)
		{
			cout << "CONGRATULATIONS! You've won an all expenses paid stay in Pyongyang, North Korea!" << endl;
			cout << "It's BYOF, bring your own food, so be sure to pack plenty. Remember: No pictures!" << endl;
		}
		else if (prizeWon == 3)
		{
			cout << "CONGRATULATIONS! You won over 5000 $10 gift cards to a variety of stores!" << endl;
			cout << "A couple of those look like they're for blockbuster and Radioshack, so use what you can!" << endl;
		}
		else if (prizeWon == 4)
		{
			cout << "CONGRATULATIONS! You won a plate of my grandma's fresh tacos!" << endl;
			cout << "Frankly, I think this is the best prize we offer. Her salsa is to die for." << endl;
		}
		else
		{
			cout << "CONGRATULATIONS! You are now $249,978 richer!" << endl;
			cout << "It was supposed to be a quarter million, but I had to pay for parking" << endl;
		}
	}
	else
	{
		cout << "OOOOOH! Looks like you got the goat, better luck next time!";
	}

		return 0;
}