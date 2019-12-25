#pragma once

#define BOARD_SIZE 8
#include <stdlib.h>     /* abs */

class Position
{
public:
	Position();
	Position(unsigned int col, unsigned int row);
	Position(char col, char row);
	Position(unsigned int index);
	Position& operator=(const Position& other);
	unsigned int column() const;
	unsigned int row() const;
	void setColumn(unsigned int newCol);
	void setRow(unsigned int newRow);
	operator unsigned int() const;
	bool operator==(const Position& other) const;
	unsigned int operator-(const Position& other) const;
	unsigned int operator||(const Position& other) const;
	bool operator/(const Position& other) const;
private:
	static unsigned int dist(unsigned int a, unsigned int b);
	static bool badIndex(unsigned int index);  // NOTE: unsigned int is by definition bigger than 0, only testing the upper limit.
	unsigned int _col;
	unsigned int _row;
};
