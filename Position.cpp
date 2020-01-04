/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Position.cpp
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/

// INCLUDES
#include "Position.h"

/*
[?] Description: A defualt constructor for the Position class.
[<-] X (none)
[->] X
*/
Position::Position() :
	_x(0), _y(0)
{
}

/*
[?] Description: A constructor for the Position class (two unsigned int based).
[<-] unsigned int x: the x coord of the position.
[<-] unsigned int y: the y coord of the position.
[->] X
*/
Position::Position(unsigned int x, unsigned int y) :
	_x(x), _y(y)
{
	if (badIndex(x) || badIndex(y))
	{
		throw "Position Out of Range";  // this should never happen, just making sure
	}
}

/*
[?] Description: A constructor for the Position class. (char based).
[<-] char x: the x coord of the position.
[<-] char y: the y coord of the position.
[->] X
*/
Position::Position(char x, char y)
{
	*this = Position((unsigned int)(x - 'a'), (y - '1'));
}

/*
[?] Description: A constructor for the Position class. (single unsigned int based).
[<-] unsigned int index: the index of the position (array like (8 * y + x)).
[->] X
*/
Position::Position(unsigned int index)
{
	*this = Position(index % BOARD_SIZE, index / BOARD_SIZE);
}

/*
[?] Description: An assignment operator for the Position class
[<-] const Position& other: the new position to be assigned to the instance.
[->] Position&: a reference to the instance.
*/
Position& Position::operator=(const Position& other)
{
	this->setX(other.x());
	this->setY(other.y());
	return *this;
}

/*
[?] Description: A getter for the x field of the Position class.
[<-] X (none)
[->] unsigned int: the x coordinate of the Position.
*/
unsigned int Position::x() const
{
	return this->_x;
}

/*
[?] Description: A getter for the y field of the Position class.
[<-] X (none)
[->] unsigned int: the y coordinate of the Position.
*/
unsigned int Position::y() const
{
	return this->_y;
}

/*
[?] Description: A setter for the x field of the Position class.
[<-] unsigned int: the new x coordinate.
[->] X (void)
*/
void Position::setX(unsigned int newX)
{
	if (badIndex(newX))
	{
		throw "Position Out of Range";
	}
	this->_x = newX;
}

/*
[?] Description: A setter for the y field of the Position class.
[<-] unsigned int: the new y coordinate.
[->] X (void)
*/
void Position::setY(unsigned int newY)
{
	if (badIndex(newY))
	{
		throw "Position Out of Range";
	}
	this->_y = newY;
}

/*
[?] Description: A static method of the Position class that tests whether or not a given coord is valid.
[<-] unsigned int index: the coord to be tested.
[->] X (void)
*/
bool Position::badIndex(unsigned int index)
{
	return (index >= BOARD_SIZE);
}

/*
[?] Description: A comparison operator of the Position class.
[<-] const Position& other: the position to be compared to the instance.
[->] bool: a boolean representation of whteher or not the two Positions are identical.
*/
bool Position::operator==(const Position& other) const
{
	return ((this->y() == other.y()) && (this->x() == other.x()));
}

/*
[?] Description: An operator that returns the absolute distance in the x axis between two positions.
[<-] const Position& other: the position whose x distance fro is to be claculated.
[->] unsigned int: the distance in the x axis from the other position.
*/
unsigned int Position::operator-(const Position& other) const
{
	return Position::dist(other.x(), this->x());
}

/*
[?] Description: An operator of the Position class that returns the absolute distance in the y axis between two positions.
[<-] const Position& other: the position whose y distance from is to be claculated.
[->] unsigned int: the distance in the y axis from the other position.
*/
unsigned int Position::operator||(const Position& other) const
{
	return Position::dist(other.y(), this->y());
}

/*
[?] Description: An operator of the Position class that returns a boolean representation of whteher or not a given Position is in the same diagonal as the instance.
[<-] const Position& other: the position to be compared with the instance.
[->] boolean representation of whteher or not the given Position is in the same diagonal as the instance.
*/
bool Position::operator/(const Position& other) const
{
	return ((*this) - other) == ((*this) || other);

}

/*
[?] Description: A conversion operator fo the Position class to unsigned int.
[<-] X (none)
[->] unsigned int: the single unsigned int version of the instance.
*/
Position::operator unsigned int()
{
	return this->y() * BOARD_SIZE + this->x();
}

/*
[?] Description: A conversion operator fo the Position class to unsigned int (const version).
[<-] X (none)
[->] unsigned int: the single unsigned int version of the instance.
*/
Position::operator const unsigned int() const
{
	return this->y() * BOARD_SIZE + this->x();
}

/*
[?] Description: A static method of the Position class that returns the absolute difference between two given unsigned ints.
[<-] unsigned int a: the firts integer.
[<-] unsigned int b: the second integer.
[->] unsigned int: the absolute difference between the two given unsigned integers.
*/
unsigned int Position::dist(unsigned int a, unsigned int b)
{
	return (unsigned int)abs((int)a - (int)b);
}