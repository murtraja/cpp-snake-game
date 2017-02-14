/*
 * Point.cpp
 *
 *  Created on: 12-Feb-2017
 *      Author: murtraja
 */

#include "Point.h"

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(int x, int y) : x(x), y(y){

}

bool Point::operator ==(const Point& point) {
	return this->x==point.x && this->y == point.y;
}

void Point::set(int x, int y) {
	this->x = x;
	this->y = y;
}
