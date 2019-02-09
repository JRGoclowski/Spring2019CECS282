# include <iostream>
#include <iomanip>
#include <cmath>
#include "Cannon.h";

using namespace std;

int main() {
	int userSeed;
	double distanceOfTarget, userAngle, userGunpowder, distanceOff;
	bool gameComplete = false;
	cout << "Please input a positive integer seed value: ";
	userSeed = GetValidIntInput(1 , 99999999);
	distanceOfTarget = GenerateTargetDistance(userSeed);
	cout << "The target is " << fixed << setprecision(2) << distanceOfTarget << "m away." << endl;
	
	while (!gameComplete) {
		cout << "Please input an angle between 0 and 90 degress: ";
		userAngle = GetValidIntInput(0, 90);

		cout << "Please input an amount of gunpowder in kilograms: ";
		userGunpowder = GetValidIntInput(0, 99999999);

		distanceOff = DistanceFromTarget(distanceOfTarget, GetDistanceCovered(userAngle, userGunpowder));
		if (distanceOff < -1) {
			cout << "You were " << fixed << setprecision(2) << abs(distanceOff) << "m short."<<endl;
		}
		else if (distanceOff > 1) {
			cout << "You were " << fixed << setprecision(2) << distanceOff << "m long." << endl;
		}
		else {
			gameComplete = true;
		}

	}
	cout << "It's a hit!" << endl;
	return 0;
}