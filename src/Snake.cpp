/*
 * Snake.cpp
 *
 *  Created on: 12-Feb-2017
 *      Author: murtraja
 */

#include "Snake.h"

Snake::Snake(){
	this->position.set(0,0);
	this->direction = Direction::left;
}

void Snake::set(Point position, Direction direction) {
	this->position = position;
	this->direction = direction;
}

Point Snake::updatePosition() {
	switch(this->direction) {
	case Direction::left:
		this->position.x--;
		break;
	case Direction::right:
		this->position.x++;
		break;
	case Direction::up:
		this->position.y--;
		break;
	case Direction::down:
		this->position.y++;
		break;
	}
	return position;
}

Snake::~Snake() {
	// TODO Auto-generated destructor stub
}

void Snake::set(Direction direction) {
	if(direction!=Direction::previous)
		this->direction = direction;
}
