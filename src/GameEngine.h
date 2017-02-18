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
#include "UserInterface.h"
#include <time.h>
#include <iostream>
using namespace std;
class GameEngine {
	Point maxBounds;
	DebugPrinter dp;
	Snake snake;
	Food food;
	RandomNumberGenerator randomizer;
	UserInterface ui;
	int score = 0;

public:
	vector<Point> getSnakePosition(){return snake.turnPoints;}
	Point getFoodPosition(){return food.position;}
	void initializeGame();
	void changeSnakeDirection(Direction direction);
	void update(Input direction);
	void printState();
	GameEngine();
	Direction getDirectionFromInput(Input);
	void run();
	~GameEngine();
};

#endif /* GAMEENGINE_H_ */
