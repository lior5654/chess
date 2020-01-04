/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Position.h
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/

#pragma once

#define BOARD_SIZE 8
#include <cmath>
#include <iostream>

class Position
{
public:
	Position();
	Position(unsigned int col, unsigned int row);
	Position(char col, char row);
	Position(unsigned int index);
	Position& operator=(const Position& other);
	unsigned int x() const;
	unsigned int y() const;
	void setX(unsigned int newX);
	void setY(unsigned int newY);
	operator unsigned int();
	operator const unsigned int() const;
	bool operator==(const Position& other) const;
	unsigned int operator-(const Position& other) const;  // row
	unsigned int operator||(const Position& other) const;  // col
	bool operator/(const Position& other) const;
private:
	static unsigned int dist(unsigned int a, unsigned int b);
	static bool badIndex(unsigned int index);  // NOTE: unsigned int is by definition bigger than 0, only testing the upper limit.
	unsigned int _x;
	unsigned int _y;
};
