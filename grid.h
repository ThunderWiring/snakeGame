/***********************************************************************
* created on 8 March 2015
* Author: bassam yassin
* website: ThunderWiring.WordPress.com
* email: bassam.yasin@gmail.com
***********************************************************************/
#ifndef _Grid_H_
#define _Grid_H_
/**********************************************************************/
/*SUMMARY:
* This header defines the basic structure used in the snake game for the-
* board, it has the data structure with interface functions as well.
***********************************************************************/
#include <cstdio>
#include <cstdlib>
#include <iostream>
/**********************************************************************/
/*_TYPE-DEFS_*/
typedef char Symbol;
typedef Symbol* Data;
/*_DEFINES_*/
const int EMPTY = 0;
const Symbol EMPTY_CELL = ' ';
/**********************************************************************/
#pragma region Point
/***********************************************************************/
/*SUMMARY:
* For makng it more easy, i am implementing the struct bellow to-
* represent the coordination of a given point in the game board.
************************************************************************/
struct Point {
	int x_coordinate, y_coordinate;
	Point(int x, int y) : x_coordinate(x), y_coordinate(y) {}
	Point() : x_coordinate(EMPTY), y_coordinate(EMPTY) {}
};/*end of struct Point{}*/
#pragma endregion 
/**********************************************************************/
#pragma region Grid
class Grid {
private:
	int Width, Length;
	Symbol symbol;
	Data data;
	/*methods:*/
	const Symbol get() const;
	void set(const Symbol);
	void initializeGrid();
	void drawBoarder();
	/*operators:*/
	void operator()(const Point point, const Symbol symbol);
	Symbol operator()(const Point point) const;
public:
	/*constructor:*/
	Grid(int width, int length, Symbol symbol);
	/*destructor:*/
	~Grid();
	/*functions:*/
	void print() const;
	void putSymbolAtPoint(const Symbol symbol, const Point point);
};
#pragma endregion
/***********************************************************************/
/* SUMMARY:
*  constructor
*/
Grid::Grid(int width, int length, Symbol symbol) : Width(width), 
	Length(length), symbol(symbol) {
	drawBoarder();
}
/***********************************************************************
*SUMMARY:*/
void Grid::operator()(const Point point, const Symbol symbol) {
	*(data + point.x_coordinate + point.y_coordinate) = symbol;
}
Symbol Grid::operator()(const Point point) const {
	return *(data + point.x_coordinate + point.y_coordinate);
}
/***********************************************************************
* SUMMARY:
* 
*/
void Grid::putSymbolAtPoint(const Symbol symbol, const Point point) {
	this->operator()(point, symbol);
}
/************************************************************************/
/* SUMMARY:
* fills the grid 'data' with 'EMPTY_CELL' symbols
*/
void Grid::initializeGrid() {
	for(int i = 0; i < (Length * Width); ++i) {
		*(data + i) = EMPTY_CELL;
	}
}
/************************************************************************/
void Grid::drawBoarder() {
	for(int i = 0; i < Length; ++i) {
		Point upperBoarder = Point(EMPTY, i);		
		//Point rightBoarder = Point(EMPTY, i);
		//Point leftBoarder = Point(EMPTY, i);
		putSymbolAtPoint(symbol, upperBoarder);
		Point lowerBoarder = Point(Length - 1, i);
		putSymbolAtPoint(symbol, upperBoarder);
	}
}
#endif /*_Grid_H_*/