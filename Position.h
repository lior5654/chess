#pragma once

#define BOARD_SIZE 8
#define POSITION_STRING_LENGTH 2

class Position
{
public:
	Position();
	Position(unsigned int col, unsigned int raw);
	Position(char col, char raw);
	Position& operator=(const Position& other);

	unsigned int col;
	unsigned int raw;
private:
	static bool badIndex(unsigned int index);  // if is less than 0 or more than BOARD_SIZE
};

