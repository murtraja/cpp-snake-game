/*
 * GameEngine.h
 *
 *  Created on: 12-Feb-2017
 *      Author: murtraja
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_
#include "Snake.h"
#include "Food.h"
#include "RandomNumberGenerator.h"
#include "DebugPrinter.h"
#include <time.h>
#include <iostream>
using namespace std;
class GameEngine {
	int xMax = 79;
	int yMax = 23;
	Snake snake;
	Food food;
	RandomNumberGenerator randomizer;
	int score = 0;
	DebugPrinter &dp;

public:
	Point getSnakePosition(){return snake.position;}
	Point getFoodPosition(){return food.position;}
	int getXMax(){return xMax;}
	int getYMax(){return yMax;}
	void initializeGame();
	void changeSnakeDirection(Direction direction);
	void update(Direction direction);
	bool isValid(Point position);
	void printState();
	GameEngine(DebugPrinter&);
	~GameEngine();
};

#endif /* GAMEENGINE_H_ */
