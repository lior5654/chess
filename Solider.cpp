/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Solider.cpp
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/

// INCLUDES
#include "Solider.h"

Solider::~Solider()
{

}

/*
[?] Description: A constructor for the Solider class.
[<-] const Position& position: An initial position for the Solider.
[<-] const Color& color: The Solider's color.
[<-] const Board* pGameBoard: a pointer to the board the Solider is in
[->] X
*/
Solider::Solider(const Position& position, const Color& color, const Board* pGameBoard) :
	_position(position), _color(color), _pBoard(pGameBoard)
{
}

/*
[?] Description: A getter for the color field of the Solider class.
[<-] X (none)
[->] Color: the color of the Solider.
*/
Color Solider::color(void) const
{
	return this->_color;
}

/*
[?] Description: A getter for the position field of the Solider class.
[<-] X (none)
[->] Position: the position of the Solider.
*/
Position Solider::position(void) const
{
	return this->_position;
}

/*
[?] Description: A getter for the pBoard field of the Solider class.
[<-] X (none)
[->] Board*: the position of the Solider.
*/
const Board* Solider::pBoard(void) const
{
	return this->_pBoard;
}

/*
[?] Description: A setter for the color field of the Solider class.
[<-] const Color& newColor: the new position to be assigned to the solider.
[->] X (void)
*/
void Solider::setColor(const Color& newColor)
{
	this->_color = newColor;
}

/*
[?] Description: A setter for the position field of the Solider class.
[<-] const Position& newPosition: the new position to be assigned to the solider.
[->] X (void)
*/
void Solider::setPosition(const Position& newPosition)
{
	this->_position = newPosition;
}


