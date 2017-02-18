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
#include "UserInput.h"
#include <time.h>
using namespace std;


int main() {
	GameEngine engine;
	engine.run();
	return 0;
}
