/*
 * GameEngine.cpp
 *
 *  Created on: 12-Feb-2017
 *      Author: murtraja
 */

#include "GameEngine.h"

GameEngine::GameEngine() : maxBounds(39, 11), randomizer(maxBounds.x,maxBounds.y, time(0)), ui(maxBounds, dp) {
	//this->initializeGame();
	dp << "inside constructor of GameEngine!\n";
}
void GameEngine::initializeGame() {
	this->score = 0;
	this->snake.set(Point(maxBounds.x, maxBounds.y), randomizer.getRandomDirection());
	this->food.set(randomizer.getRandomPoint(snake.turnPoints[0]));
	dp<<"Game initialized with the state:\n";
	this->printState();
}
Direction GameEngine::getDirectionFromInput(Input input) {
	switch(input) {
	case Input::goLeft:
		return Direction::left;
	case Input::goRight:
		return Direction::right;
	case Input::goUp:
		return Direction::up;
	case Input::goDown:
		return Direction::down;
	default:
		return snake.direction;
	}
}
void GameEngine::update(Input input) {
	switch(input) {
	case Input::quit:
		return;
	case Input::restart:
		this->initializeGame();
		return;
	}
	Direction direction = getDirectionFromInput(input);

	//check if snake is eating itself

	//check if snake is out of bounds
	Point newHead = snake.moveHead(direction);
	if(newHead == food.position) {
		score ++;
		food.position = randomizer.getRandomPoint(newHead);
	} else {

		snake.moveTail();
	}
	printState();
}

void GameEngine::printState() {
	dp<<"Snake @ "<<snake.turnPoints<<" going "<<snake.direction<<"\n";
	dp<<"Food  @ "<<food.position<<"\n";
	dp<<"Score @ "<<score<<"\n";
}
void GameEngine::changeSnakeDirection(Direction direction) {
	snake.set(direction);
}
GameEngine::~GameEngine() {
	// TODO Auto-generated destructor stub
	dp << "inside destructor of GameEngine!\n";
}

void GameEngine::run() {
	Input input = Input::quit;
	this->initializeGame();
	do {
		ui.paint(snake.turnPoints, food.position);
		input = ui.getUserInput();
		dp << "User input received: "<<input<<"\n";
		update(input);
	}while(input != Input::quit);
}

