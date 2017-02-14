/*
 * Food.cpp
 *
 *  Created on: 12-Feb-2017
 *      Author: murtraja
 */

#include "Food.h"

Food::Food() {

}

void Food::set(int x, int y) {
	 position.set(x,y);
}

void Food::set(Point position) {
	 this->position = position;
}

Food::~Food() {
	// TODO Auto-generated destructor stub
}

