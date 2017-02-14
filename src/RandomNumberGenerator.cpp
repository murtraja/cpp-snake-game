/*
 * RandomNumberGenerator.cpp
 *
 *  Created on: 12-Feb-2017
 *      Author: murtraja
 */

#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator(int xMax, int yMax, int seed):random_engine(seed), xDistribution(0, xMax), yDistribution(0, yMax) {
	this->xMax = xMax;
	this->yMax = yMax;
}

RandomNumberGenerator::~RandomNumberGenerator() {
	// TODO Auto-generated destructor stub
}

int RandomNumberGenerator::getRandomNumber(int notThisNumber, uniform_int_distribution<int> distribution) {
	int newNumber = notThisNumber;
	while(newNumber==notThisNumber) {
		newNumber = distribution(random_engine);
	}
	return newNumber;
}

int RandomNumberGenerator::getRandomNumber(int low, int high) {
	uniform_int_distribution<int> distribution(low, high);
	return distribution(random_engine);
}

Point RandomNumberGenerator::getRandomPoint(Point notThisPoint) {
	int newX = getRandomNumber(notThisPoint.x, xDistribution);
	int newY = getRandomNumber(notThisPoint.y, yDistribution);
	return  Point(newX, newY);
}

Direction RandomNumberGenerator::getRandomDirection() {
	int directionalNumber = this->getRandomNumber(0,3);
	Direction direction;
	switch(directionalNumber) {
		case 0:
			direction = Direction::left;
			break;
		case 1:
			direction = Direction::right;
			break;
		case 2:
			direction = Direction::up;
			break;
		default:
			direction = Direction::down;
		}
	return direction;
}
