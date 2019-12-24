#pragma once

#define BOARD_SIZE 8

class Position
{
public:
	Position();
	Position(unsigned int col, unsigned int row);
	Position(char col, char row);
	Position& operator=(const Position& other);
	unsigned int column() const;
	unsigned int row() const;
private:
	static bool badIndex(unsigned int index);  // NOTE: unsigned int is by definition bigger than 0, only testing the upper limit.
	unsigned int _col;
	unsigned int _row;
};

