/*
 * Snake.h
 *
 *  Created on: 12-Feb-2017
 *      Author: murtraja
 */

#ifndef SNAKE_H_
#define SNAKE_H_
#include "Point.h"
#include "Direction.h"
class Snake {
	Point position;
	Direction direction;
	// these represent the coordinates of the head
public:
	Snake();
	void set(Point position, Direction direction);
	void set(Direction direction);
	Point updatePosition();
	~Snake();
	friend class GameEngine;
};

#endif /* SNAKE_H_ */
