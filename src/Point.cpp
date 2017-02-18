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
int Point::operator - (const Point& point) {
	Point difference(0,0);
	if(this->x == point.x)
		return this->y - point.y;
	else if(this->y == point.y)
		return this->x - point.x;
	return 0;
}

Point Point::operator << (const Point& point) {
	if(this->x == point.x) {
		int difference = point.y - this->y;
		int signum = (difference>0) - (difference<0);
		return Point(x, this->y + signum);
	}
	else if(this->y == point.y) {
		int difference = point.x - this->x;
		int signum = (difference>0) - (difference<0);
		return Point(this->x+signum, point.y);
	}
	return Point(-1, -1);
}
void Point::set(int x, int y) {
	this->x = x;
	this->y = y;
}
