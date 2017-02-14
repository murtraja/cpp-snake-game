/*
 * RandomNumberGenerator.h
 *
 *  Created on: 12-Feb-2017
 *      Author: murtraja
 */

#ifndef RANDOMNUMBERGENERATOR_H_
#define RANDOMNUMBERGENERATOR_H_
#include <random>
#include "Point.h"
#include "Direction.h"
using namespace std;

class RandomNumberGenerator {
	int xMax, yMax;
	mt19937 random_engine;
	uniform_int_distribution<int> xDistribution, yDistribution;
public:
	RandomNumberGenerator(int, int, int);
	~RandomNumberGenerator();
	int getRandomNumber(int, uniform_int_distribution<int>);
	int getRandomNumber(int low, int high);
	Point getRandomPoint(Point);
	Direction getRandomDirection();
};

#endif /* RANDOMNUMBERGENERATOR_H_ */
