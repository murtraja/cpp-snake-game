/*
 * DebugPrinter.cpp
 *
 *  Created on: 14-Feb-2017
 *      Author: murtraja
 */

#include "DebugPrinter.h"

DebugPrinter::DebugPrinter() : ofs(fileName, ofstream::out){
	ofs<<"-----start-----\n";
}

DebugPrinter::~DebugPrinter() {
	ofs<<"------end------\n";
	ofs.close();
}

void DebugPrinter::print(string message) {
	ofs<<message<<endl;
}
DebugPrinter& DebugPrinter::operator<<(string str) {
	ofs<<str;
	ofs.flush();
	return *this;
}
DebugPrinter& DebugPrinter::operator<<(int num) {
	ofs<<num;
	ofs.flush();
	return *this;
}
DebugPrinter& DebugPrinter::operator<<(Direction direction) {
	string str;
	switch(direction) {
	case Direction::up:
		str = "UP";
		break;
	case Direction::down:
		str = "DOWN";
		break;
	case Direction::left:
		str = "LEFT";
		break;
	case Direction::right:
		str = "RIGHT";
		break;
	default:
		str = "UNKNOWN";
	}
	ofs<<str;
	ofs.flush();
	return *this;
}
DebugPrinter& DebugPrinter::operator<<(Input input) {
	string str;
	switch(input) {
	case Input::goUp:
		str = "Go UP";
		break;
	case Input::goDown:
		str = "Go DOWN";
		break;
	case Input::goLeft:
		str = "Go LEFT";
		break;
	case Input::goRight:
		str = "Go RIGHT";
		break;
	case Input::restart:
		str = "restart";
		break;
	case Input::quit:
		str = "quit";
		break;
	case Input::noInput:
		str = "no input received";
		break;
	default:
		str = "UNKNOWN";
	}
	ofs<<str;
	ofs.flush();
	return *this;
}
DebugPrinter& DebugPrinter::operator<<(Point point) {
	ofs<<"("<<point.x<<", "<<point.y<<")";
	ofs.flush();
	return *this;
}
DebugPrinter& DebugPrinter::operator<<(vector<Point> points) {
	for(Point point: points) {
		*this<<point;
	}
	return *this;
}
