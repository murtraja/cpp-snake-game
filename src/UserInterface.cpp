/*
 * UserInterface.cpp
 *
 *  Created on: 14-Feb-2017
 *      Author: murtraja
 */

#include "UserInterface.h"

UserInterface::UserInterface(Point maxBounds, DebugPrinter& dPrinter) : maxBounds(maxBounds), dp(dPrinter) {
	initscr();                      /* Start curses mode            */
	raw();                          /* Line buffering disabled      */
	keypad(stdscr, TRUE);           /* We get F1, F2 etc..          */
	noecho();
	halfdelay(3);
	curs_set(0);
}

UserInterface::~UserInterface() {
	cbreak();
	getch();
	endwin();
}

void UserInterface::paint(vector<Point>& snakePosition, Point& foodPosition) {
	clear();
	dp<<"now painting @"<<snakePosition<<" for snake and "<<foodPosition<<" for food\n";
	for(unsigned int i=0; i<snakePosition.size()-1; i++) {
		Point current = snakePosition[i];
		Point next = snakePosition[i+1];
		if(current.x == next.x) {
			mvvline(min(current.y, next.y), current.x, 's', abs(current-next)+1);
		}
		else if(current.y == next.y) {
			mvhline(current.y, min(current.x, next.x), 's', abs(current-next)+1);
		}
	}

	mvaddch(foodPosition.y, foodPosition.x, 'f');
	refresh();
}

Input UserInterface::getUserInput() {
	int ch = getch();
	switch(ch) {
	case KEY_LEFT:
		return Input::goLeft;
	case KEY_RIGHT:
		return Input::goRight;
	case KEY_DOWN:
		return Input::goDown;
	case KEY_UP:
		return Input::goUp;
	case 'q':
		return Input::quit;
	}
	return Input::noInput;
}
