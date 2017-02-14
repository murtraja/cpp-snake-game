/*
 * UserInterface.cpp
 *
 *  Created on: 14-Feb-2017
 *      Author: murtraja
 */

#include "UserInterface.h"

UserInterface::UserInterface(int xMax, int yMax, DebugPrinter& dPrinter) : xMax(xMax), yMax(yMax), dp(dPrinter) {
	initscr();                      /* Start curses mode            */
	raw();                          /* Line buffering disabled      */
	keypad(stdscr, TRUE);           /* We get F1, F2 etc..          */
	noecho();
	halfdelay(9);
	curs_set(0);
}

UserInterface::~UserInterface() {
	cbreak();
	getch();
	endwin();
}

void UserInterface::paint(Point snakePosition, Point foodPosition) {
	clear();
	dp<<"now painting @"<<snakePosition<<" for snake and "<<foodPosition<<" for food\n";
	mvaddch(snakePosition.y, snakePosition.x, 's');
	mvaddch(foodPosition.y, foodPosition.x, 'f');
	refresh();
}

Direction UserInterface::getUserInput() {
	int ch = getch();
	switch(ch) {
	case KEY_LEFT:
		return Direction::left;
	case KEY_RIGHT:
		return Direction::right;
	case KEY_DOWN:
		return Direction::down;
	case KEY_UP:
		return Direction::up;
	case 'q':
		return Direction::quit;
	}
	return Direction::previous;
}
