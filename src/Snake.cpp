/*
 * Snake.cpp
 *
 *  Created on: 12-Feb-2017
 *      Author: murtraja
 */

#include "Snake.h"

Snake::Snake(){
	// be lazy
	direction = Direction::down;
}

void Snake::set(Point position, Direction direction) {
	if(this->turnPoints.size()==0) {
		turnPoints.push_back(position);
		turnPoints.push_back(position);
	}
	this->direction = direction;
}

bool Snake::updatePosition(Direction direction) {
	/*
	 * this function updates the position
	 * of the snake depending on its direction
	 *
	 */

	return true;
}
vector<Point> Snake::updatePosition() {
	switch(this->direction) {
	case Direction::left:
		this->turnPoints[0].x--;
		break;
	case Direction::right:
		this->turnPoints[0].x++;
		break;
	case Direction::up:
		this->turnPoints[0].y--;
		break;
	case Direction::down:
		this->turnPoints[0].y++;
		break;
	}
	return turnPoints;
}
Snake::~Snake() {
	// TODO Auto-generated destructor stub
}

void Snake::set(Direction direction) {
	this->direction = direction;
}

Point Snake::getNextHeadPosition() {
	return this->getNextHeadPosition(this->direction);
}

Point Snake::getNextHeadPosition(Direction direction) {
	Point position = this->turnPoints[0];
	switch(direction) {
		case Direction::left:
			position.x--;
			break;
		case Direction::right:
			position.x++;
			break;
		case Direction::up:
			position.y--;
			break;
		case Direction::down:
			position.y++;
			break;
		}
	return position;
}

void Snake::eatFood(Point food) {
	/*
	 * pre conditions:
	 * the food is near the head
	 *
	 * just elongate the snake, there are two cases here
	 * if the food is collinear with snake's body, just
	 * increment the head position accordingly
	 * if the food is not collinear, just add the food
	 * position and make it the new head
	 *
	 * the case that the snake is just
	 */

	if(this->isCollinearWith(food)) {
		this->turnPoints[0] = food;
		return;
	}
	this->turnPoints.insert(turnPoints.begin(), food);


}
bool Snake::isCollinearWith(Point point) {
	if (this->turnPoints.size()==1)
		return true;
	else return (turnPoints[0].x==turnPoints[1].x && turnPoints[0].x==point.x) || (turnPoints[0].y==turnPoints[1].y && turnPoints[0].y==point.y);
}
Point Snake::moveHead(Direction direction) {
	/*
	 * this function moves the head
	 * in the direction direction
	 */
	Point nextPoint = getNextHeadPosition(direction);
	if(this->isCollinearWith(nextPoint)) {
		this->turnPoints[0] = nextPoint;
	}
	else {
		this->turnPoints.insert(turnPoints.begin(), nextPoint);
	}
	this->direction = direction;
	return turnPoints[0];
}
void Snake::moveTail() {
	/*
	 * this function moves the tail
	 * in the natural direction
	 */
	int lastIndex = turnPoints.size()-1;
	Point penTail = turnPoints[lastIndex-1];
	Point tail = turnPoints[lastIndex];
	Point newTail = tail << penTail;
	if(newTail == penTail && lastIndex>1)
		turnPoints.pop_back();
	else
		turnPoints[lastIndex] = newTail;

}
