#pragma once

#define BOARD_SIZE 8

class Position
{
public:
	Position(unsigned int col, unsigned int raw);
	Position(char col, char raw);

	unsigned int col;
	unsigned int raw;
private:
	static bool badIndex(unsigned int index);  // if is less than 0 or more than BOARD_SIZE
};

