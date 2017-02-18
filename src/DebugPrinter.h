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
#include "UserInput.h"
#include <vector>
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
	DebugPrinter& operator<<(Input input);
	DebugPrinter& operator<<(Point point);
	DebugPrinter& operator<<(vector<Point>);
};

#endif /* DEBUGPRINTER_H_ */
