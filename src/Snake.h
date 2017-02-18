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
#include <vector>
using namespace std;
class Snake {
	vector<Point> turnPoints;
	//this vector represents the snake, the head is position[0]
	// and the corresponding "turns" are represented by position[i], i>0
	Direction direction;
	// these represent the coordinates of the head
public:
	Snake();
	void set(Point position, Direction direction);
	void set(Direction direction);
	bool updatePosition(Direction direction);
	vector<Point> updatePosition();
	~Snake();
	Point getNextHeadPosition(Direction direction);
	Point getNextHeadPosition();
	void eatFood(Point foodPosition);
	bool isCollinearWith(Point point);
	Point moveHead(Direction direction);
	void moveTail();
	friend class GameEngine;
};

#endif /* SNAKE_H_ */
