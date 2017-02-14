/*
 * DebugPrinter.h
 *
 *  Created on: 14-Feb-2017
 *      Author: murtraja
 */

#ifndef DEBUGPRINTER_H_
#define DEBUGPRINTER_H_
#include <string>
#include <fstream>
#include "Direction.h"
#include "Point.h"
using namespace std;
class DebugPrinter {
	string fileName = "debugOutput.txt";
	ofstream ofs;
public:
	DebugPrinter();
	void print(string);
	~DebugPrinter();
	DebugPrinter& operator<<(string str);
	DebugPrinter& operator<<(int num);
	DebugPrinter& operator<<(Direction direction);
	DebugPrinter& operator<<(Point point);
};

#endif /* DEBUGPRINTER_H_ */
