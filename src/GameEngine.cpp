/*
 * GameEngine.cpp
 *
 *  Created on: 12-Feb-2017
 *      Author: murtraja
 */

#include "GameEngine.h"

GameEngine::GameEngine(DebugPrinter& dPrinter) : randomizer(xMax,yMax, time(0)), dp(dPrinter) {
	this->initializeGame();
}
void GameEngine::initializeGame() {
	this->score = 0;
	this->snake.set(Point(xMax/2, yMax/2), randomizer.getRandomDirection());
	this->food.set(randomizer.getRandomPoint(snake.position));
}

void GameEngine::update(Direction direction) {
	snake.set(direction);
	Point newSnakePosition = snake.updatePosition();
	/*
	 * now check for cases here like if the snake was out of bounds
	 * or if the snake consumed food
	 */
	if(isValid(newSnakePosition)) {
		if(newSnakePosition == food.position) {
			// increment score
			// place food on some other coordinate
			score++;
			food.position = randomizer.getRandomPoint(newSnakePosition);
		}
	} else {
		// the game is over here!
	}
	printState();
}

bool GameEngine::isValid(Point position) {
	return position.x>=0 && position.x<=xMax && position.y>=0 && position.y<=yMax;
}

void GameEngine::printState() {
	dp<<"Snake @ "<<snake.position<<" going "<<snake.direction<<"\n";
	dp<<"Food  @ "<<food.position<<"\n";
	dp<<"Score @ "<<score<<"\n\n";
}
void GameEngine::changeSnakeDirection(Direction direction) {
	snake.set(direction);
}
GameEngine::~GameEngine() {
	// TODO Auto-generated destructor stub
}

