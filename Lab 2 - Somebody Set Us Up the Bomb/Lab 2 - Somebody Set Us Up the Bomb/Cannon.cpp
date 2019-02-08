#include <iostream>
#include <random>
#include <cmath>
using namespace std;

double GetDistanceCovered(double userAngle, double powder) {
	double radsAngle = userAngle *(3.141592653589793238463/180);
	double time = ((sin(radsAngle) * 30 * powder) * 2) / (9.8);
	double horizontalDistance = cos(radsAngle) * 30 * powder * time;
	return horizontalDistance;
}

double GetValidIntInput(double lowerBound, double upperBound) {
	double userInput;
	cin >> userInput;
	while (userInput < lowerBound || userInput > upperBound) {
		cin >> userInput;
	}
	return userInput;
}

double GenerateTargetDistance(int seed) {
	mt19937 engine(seed);
	uniform_real_distribution<> range(1.00, 1000.00);
	return range(engine);
}

double DistanceFromTarget(double targetDistance, double horizontalDistance) { return horizontalDistance - targetDistance; }