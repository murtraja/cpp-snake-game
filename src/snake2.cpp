//============================================================================
// Name        : snake2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "GameEngine.h"
#include "RandomNumberGenerator.h"
#include "Direction.h"
#include "UserInterface.h"
#include "DebugPrinter.h"
#include <time.h>
#include <thread>
using namespace std;


int main() {
	//cout << "!!!Hello World!!!" << endl<<__cplusplus<<endl; // prints !!!Hello World!!!
	DebugPrinter dPrinter;
	GameEngine engine(dPrinter);
	UserInterface ui(engine.getXMax(), engine.getYMax(), dPrinter);
	while(true) {
		ui.paint(engine.getSnakePosition(), engine.getFoodPosition());
		Direction direction = ui.getUserInput();
		if(direction == Direction::quit)
			break;
		engine.update(direction);
	}

	return 0;
}
