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

Position::Position(unsigned int index)
{
	*this = Position(index % BOARD_SIZE, index / BOARD_SIZE);
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

void Position::setColumn(unsigned int newCol)
{
	if (badIndex(newCol))
	{
		throw "Position Out of Range";
	}
	this->_col = newCol;
}
void Position::setRow(unsigned int newRow)
{
	if (badIndex(newRow))
	{
		throw "Position Out of Range";
	}
	this->_row = newRow;
}

bool Position::badIndex(unsigned int index)
{
	return (index >= BOARD_SIZE);
}

bool Position::operator==(const Position& other) const
{
	return ((this->row() == other.row()) && (this->column() == other.column()));
}
unsigned int Position::operator-(const Position& other) const
{
	return Position::dist(other.row(), this->row());
}
unsigned int Position::operator||(const Position& other) const
{
	return Position::dist(other.column(), this->column());
}
int Position::operator/(const Position& other) const
{
	if ((*this) - other != (*this) || other)
	{
		return 0;
	}
	else if (!((*this).row() - other.row() > 0) ^ (*this).column() - other.column() > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}

}
Position::operator unsigned int() const
{
	return this->row() * BOARD_SIZE + this->column();
}

unsigned int Position::dist(unsigned int a, unsigned int b)
{
	return (unsigned int)abs((int)a - (int)b);
}