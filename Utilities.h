/***********************************************************************
* created on 8 March 2015
* Author: bassam yassin
* website: ThunderWiring.WordPress.com
* email: bassam.yasin@gmail.com
***********************************************************************/
#ifndef _UTILITIES_H
#define _UTILITIES_H
/**********************************************************************
*SUMMARY:
* This header has all the classes and thier implementation that are
* used for construction of the game
************************************************************************/
/*_INCLUDES:_*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "grid.h"
/***********************************************************************/
/*_DEFINES:_*/
const char BOARDER = '*';
const char SPACE = ' ';
const char SNAKE_PART = '0';
const int DEFAULT_GAME_DURATION = 100; /*max length of the snake*/
const int DEFUALT_LENGTH = 20;
const int DEFUALT_WIDTH = 50;
const int TOP_AND_BOTTOM_BOARDER = 2;
const int SIDES = 2;
/*_TYPE-DEFS_*/
typedef enum direction_t {Forward, Backward, Left, Right} Direction;

#pragma region MovingObject
/************************************************************************/
/* SUMMARY:
 * Abstract class inherted by all moving objects in the game.
 * Has all the functions needed to move a char(symbol) on the console.
 ************************************************************************/
class MovingObject {
private:
	char symbol;
	Point start;
	/*methods:*/	
public:
	/*constructors:*/
	MovingObject();
	MovingObject(const char symbol, const Point startAt);
	/*functions:*/
	virtual void move(Direction direction);
protected:	
};
/***********************************************************************/
/*implementation of class 'MovingObject'*/
/***********************************************************************/
/* SUMMARY:
* default and non-default constructors implementations
*/
MovingObject::MovingObject(const char symbol, const Point startAt)
	: symbol(symbol), start(startAt) {}
MovingObject::MovingObject() : symbol(SNAKE_PART) {}
/***********************************************************************/
/* SUMMARY:
* moves the object(char/s) across the grid
*/
void MovingObject::move(Direction direction) {} //TODO: Implement
/***********************************************************************/
/*end of MovingObject{} implementation*/
#pragma endregion 
#pragma region Snake
/************************************************************************/
/* SUMMARY:
 * That class has all the data and functions to control a moving snake
 * in the board
 ************************************************************************/
class Snake : public MovingObject {
private:
	int maxLength, currentLength;
	Point startPosition;
	/*methods:*/
	void moveForward_aux();		//TODO: implement!
	void moveBackward_aux();	//TODO: implement!
	void moveLeft_aux();		//TODO: implement!
	void moveRight_aux();		//TODO: implement!
public:
	/*constructor*/	
	Snake(Point startAt, int maxLen);
	Snake();
	/*functions:*/
	void moveSnake(Direction direction);	//TODO: implement!
};/*end of class Snake{}*/
/***********************************************************************/
/*implementation of class 'Snake'*/
/***********************************************************************/
/* SUMMARY:
* implementation of te class 'Snake' non-default constructor
*/
Snake::Snake(Point startAt, int maxLen) :
	  maxLength(DEFAULT_GAME_DURATION), currentLength(EMPTY), 
		  startPosition(startAt) {}
/***********************************************************************/
/* SUMMARY:
* implementation of te class 'Snake' default constructor
*/
Snake::Snake() : maxLength(DEFAULT_GAME_DURATION), currentLength(EMPTY) {}
/***********************************************************************/
void Snake::moveSnake(Direction direction) {
	switch(direction) {
	case Forward:
		moveForward_aux();
		break;
	case Backward:
		moveBackward_aux();
		break;
	case Left:
		moveLeft_aux();
		break;
	case Right:
		moveRight_aux();
		break;
	}
}
/***********************************************************************/
void Snake::moveRight_aux() {}			//TODO: implement!
void Snake::moveLeft_aux() {}			//TODO: implement!
void Snake::moveForward_aux() {}		//TODO: implement!
void Snake::moveBackward_aux() {}		//TODO: implement!
/*end of 'Snake' implementation*/
#pragma endregion 
#pragma region Board
/***********************************************************************/
/* SUMMARY:
* initialize the game, draws the arena of the game and starts the 'Snake'
* object of the game
************************************************************************/
class Board {
private:	
	int Width, Length;
	Point Center;
	Snake snake;
	/*methods:*/
	void drawBoard() const;
	void draw_aux(const char charToDraw, const int iterations) const;
	void initializeBoard();
public:
	/*constructors*/
	Board(int width, int length) : Width(width), Length(length) {
		Center = Point(Width/2, Length/2);		
		snake = Snake(Center, DEFAULT_GAME_DURATION);
		initializeBoard();
	}
	Board() : Width(DEFUALT_WIDTH), Length(DEFUALT_LENGTH) {
		Center = Point(Width/2, Length/2);		
		snake = Snake(Center, DEFAULT_GAME_DURATION);
		initializeBoard();
	}
	/*functions*/
	void pressKeyEvent();		//TODO: implement!
};/*end of class Board{}*/
/***********************************************************************/
/*implementation of class 'Board'*/
/***********************************************************************/
/*SUMMARY:
* Initialized the parameters of the game
* Draw the arena of the game
*/
void Board::initializeBoard() {		//TODO: implement!
	drawBoard();
}
/***********************************************************************/
/*SUMMARY:
* Draw the boarder of the game board using the defined char 'BOARDER', 
* dimentions of the board are initialized in the constructor
*/
void Board::drawBoard() const {
	draw_aux(BOARDER, Width);
	std::cout << std::endl;
	for(int i = 0; i < Length - TOP_AND_BOTTOM_BOARDER; ++i) {
		std::cout << BOARDER;
		draw_aux(SPACE, Width - SIDES);
		std::cout << BOARDER << std::endl;
	}	
	draw_aux(BOARDER, Width);
	std::cout << std::endl;
}
/***********************************************************************/
/*SUMMARY:
* An auxilary function that prints a given char as the number of times-
* given in a single line
*/
void Board::draw_aux(const char charToDraw, const int iterations) const {
	for(int i = 0; i < iterations; ++i) {
		std::cout << charToDraw;
	}
}
/***********************************************************************/
/*end of 'Board' implementation*/
#pragma endregion 
#endif /*_UTILITIES_H*/