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
		std::cerr << "E X C E P T I ON   R E E E E E" << std::endl;
		throw "Position Out of Range";
	}
}

Position::Position(char col, char row)
{
	*this = Position((unsigned int)(col - 'a'), (row - '1'));
}

Position::Position(unsigned int index)
{
	*this = Position(index % BOARD_SIZE, index / BOARD_SIZE);
}
Position& Position::operator=(const Position& other)
{
	this->setColumn(other.column());
	this->setRow(other.row());
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
	return Position::dist(other.column(), this->column());
}
unsigned int Position::operator||(const Position& other) const
{
	return Position::dist(other.row(), this->row());
}
int Position::operator/(const Position& other) const
{
	return ((*this) - other) == ((*this) || other);

}
Position::operator unsigned int()
{
	return this->row() * BOARD_SIZE + this->column();
}
Position::operator const unsigned int() const
{
	return this->row() * BOARD_SIZE + this->column();
}
unsigned int Position::dist(unsigned int a, unsigned int b)
{
	return (unsigned int)abs((int)a - (int)b);
}