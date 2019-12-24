// INCLUDES
#include "Position.h"

// FUNCTIONS & METHODS
Position::Position() :
	_col(0), _row(0)
{
}

Position::Position(unsigned int col, unsigned int row) :
	_col(col), _row(row)
{
	if (badIndex(col) || badIndex(row))
	{
		throw "Position Out of Range";
	}
}

Position::Position(char col, char row)
{
	*this = Position(((unsigned int)'a' - col), (row - (unsigned int)'0' - 1));
}

Position& Position::operator=(const Position& other)
{
	*this = Position(other.column(), other.row());
	return *this;
}

// col getter
unsigned int Position::column() const
{
	return this->_col;
}

// row getter
unsigned int Position::row() const
{
	return this->_row;
}

bool Position::badIndex(unsigned int index)
{
	return (index >= BOARD_SIZE);
}
