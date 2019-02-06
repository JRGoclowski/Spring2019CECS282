#include <iostream>
#include <random>
#include <cmath>
using namespace std;

double GetDistanceCovered(double userAngle, double powder) {
	double radsAngle = userAngle * 0.0174533;
	double time = 2 * sin(radsAngle) / (9.8);
	double horizontalDistance = cos(radsAngle) * 30 * powder * time;
	return horizontalDistance;
}

double GetValidIntInput(int lowerBound, int upperBound) {
	double userInput;
	cin >> userInput;
	while (userInput < lowerBound || userInput > upperBound) {
		cin >> userInput;
	}
	return userInput;
}

double GenerateTargetDistance(int seed) {
	mt19937 engine(seed);
	return engine();
}

double DistanceFromTarget(int targetDistance, int horizontalDistance) { return horizontalDistance - targetDistance; }