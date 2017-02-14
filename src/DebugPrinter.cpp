/*
 * DebugPrinter.cpp
 *
 *  Created on: 14-Feb-2017
 *      Author: murtraja
 */

#include "DebugPrinter.h"

DebugPrinter::DebugPrinter() : ofs(fileName, ofstream::out | ofstream::ate){
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
	return *this;
}
DebugPrinter& DebugPrinter::operator<<(int num) {
	ofs<<num;
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
	return *this;
}
DebugPrinter& DebugPrinter::operator<<(Point point) {
	ofs<<"("<<point.x<<", "<<point.y<<")";
	return *this;
}
