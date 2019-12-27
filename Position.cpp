// INCLUDES
#include "Position.h"

// FUNCTIONS & METHODS
Position::Position() :
	_x(0), _y(0)
{
}

Position::Position(unsigned int x, unsigned int y) :
	_x(x), _y(y)
{
	if (badIndex(x) || badIndex(y))
	{
		std::cerr << "E X C E P T I ON   R E E E E E" << std::endl;
		throw "Position Out of Range";
	}
}

Position::Position(char x, char y)
{
	*this = Position((unsigned int)(x - 'a'), (y - '1'));
}

Position::Position(unsigned int index)
{
	*this = Position(index % BOARD_SIZE, index / BOARD_SIZE);
}
Position& Position::operator=(const Position& other)
{
	this->setX(other.x());
	this->setY(other.y());
	return *this;
}

// col getter
unsigned int Position::x() const
{
	return this->_x;
}

// row getter
unsigned int Position::y() const
{
	return this->_y;
}

void Position::setX(unsigned int newCol)
{
	if (badIndex(newCol))
	{
		throw "Position Out of Range";
	}
	this->_x = newCol;
}
void Position::setY(unsigned int newRow)
{
	if (badIndex(newRow))
	{
		throw "Position Out of Range";
	}
	this->_y = newRow;
}

bool Position::badIndex(unsigned int index)
{
	return (index >= BOARD_SIZE);
}

bool Position::operator==(const Position& other) const
{
	return ((this->y() == other.y()) && (this->x() == other.x()));
}
unsigned int Position::operator-(const Position& other) const
{
	return Position::dist(other.x(), this->x());
}
unsigned int Position::operator||(const Position& other) const
{
	return Position::dist(other.y(), this->y());
}
int Position::operator/(const Position& other) const
{
	return ((*this) - other) == ((*this) || other);

}
Position::operator unsigned int()
{
	return this->y() * BOARD_SIZE + this->x();
}
Position::operator const unsigned int() const
{
	return this->y() * BOARD_SIZE + this->x();
}
unsigned int Position::dist(unsigned int a, unsigned int b)
{
	return (unsigned int)abs((int)a - (int)b);
}