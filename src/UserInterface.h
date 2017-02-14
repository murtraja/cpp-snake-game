/*
 * UserInterface.h
 *
 *  Created on: 14-Feb-2017
 *      Author: murtraja
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_
#include <ncurses.h>
#include "Direction.h"
#include "Point.h"
#include "DebugPrinter.h"
/*
 * planning to make three windows
 * one for border, one for the game
 * and the other for score and status, etc.
 */
class UserInterface {
	int xMax, yMax;
	int symbolSnake = ACS_DIAMOND;
	int symbolFood = ACS_PLUS;
	DebugPrinter& dp;
public:
	UserInterface(int, int, DebugPrinter&);
	void paint(Point snakePosition, Point foodPosition);
	Direction getUserInput();
	~UserInterface();
};

#endif /* USERINTERFACE_H_ */
