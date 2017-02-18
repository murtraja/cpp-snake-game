/*
 * Point.h
 *
 *  Created on: 12-Feb-2017
 *      Author: murtraja
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
public:
	int x, y;
	Point();
	Point(int x, int y);
	bool operator == (const Point& point);
	int operator - (const Point& point);
	Point operator << (const Point& point);
	void set(int x, int y);
};

#endif /* POINT_H_ */
