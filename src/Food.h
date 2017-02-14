/*
 * Food.h
 *
 *  Created on: 12-Feb-2017
 *      Author: murtraja
 */

#ifndef FOOD_H_
#define FOOD_H_
#include "Point.h"
class Food {
	Point position;
public:
	void set(int x, int y);
	void set(Point p);
	Food();
	~Food();
	friend class GameEngine;
};

#endif /* FOOD_H_ */
