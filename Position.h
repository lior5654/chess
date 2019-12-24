#pragma once

#define BOARD_SIZE 8

class Position
{
public:
	Position(unsigned int col, unsigned int raw);
<<<<<<< HEAD
	Position(char col, char raw);

	unsigned int col;
	unsigned int raw;
private:
	static bool badIndex(unsigned int index);  // if is less than 0 or more than BOARD_SIZE
=======
	unsigned int col;
	unsigned int row;
>>>>>>> 5f2baba73d70dca0334398af8846c14b505480b6
};

