/*
 * UserInterface.h
 *
 *  Created on: 14-Feb-2017
 *      Author: murtraja
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_
#include <ncurses.h>
#include <vector>
#include "Direction.h"
#include "Point.h"
#include "DebugPrinter.h"
#include "UserInput.h"
/*
 * planning to make three windows
 * one for border, one for the game
 * and the other for score and status, etc.
 */
class UserInterface {
	Point maxBounds;
	int symbolSnake = ACS_DIAMOND;
	int symbolFood = ACS_PLUS;
	DebugPrinter& dp;
public:
	UserInterface(Point, DebugPrinter&);
	void paint(vector<Point>& snakePosition, Point& foodPosition);
	Input getUserInput();
	~UserInterface();
};

#endif /* USERINTERFACE_H_ */
