#include "Position.h"

Position::Position()
{
	this->col = 0;
	this->raw = 0;
}

Position::Position(unsigned int col, unsigned int raw)
{
	if (badIndex(col) || badIndex(raw))
	{
		// TO DO: exception
	}
	this->col = col;
	this->raw = raw;
}

Position::Position(char col, char raw)
{
	// a2 -> (0, 1)

	// convert
	unsigned int colInt = (unsigned int)'a' - col;
	unsigned int rawInt = raw - '0' - 1;

	*this = Position(colInt, rawInt);
}

Position& Position::operator=(const Position& other)
{
	*this = Position(other.col, other.raw);
	return *this;
}

bool Position::badIndex(unsigned int index)
{
	if (index >= BOARD_SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
