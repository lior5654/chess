/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Queen.cpp
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/

// INCLUDES
#include "Queen.h"

/*
[?] Description: A constructor for the Queen class.
[<-] const Position& position: An initial position for the Queen.
[<-] const Color& color: The Queen's color.
[<-] const Board* pGameBoard: a pointer to the board the Queen is in
[->] X
*/
Queen::Queen(const Position& position, const Color& color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard)
{
	// allocating memory for the queen's Rook & Bishop
	this->_pRook = new Rook(position, color, pGameBoard);
	this->_pBishop = new Bishop(position, color, pGameBoard);
}

/*
[?] Description: A method of the Queen class that overrides the canMove abstract method of the Solider class the purpose of which is to test whether or not the Queen at its current state can move to a given destination.
[<-] const Position& dest: the destination to test whether or not the Queen in its current state can move to.
[->] bool: a boolean representation of whether or not the Queen can move to the given destination.
*/
bool Queen::canMove(const Position& dest)
{
	return this->_pRook->canMove(dest) || this->_pBishop->canMove(dest);
}

/*
[?] Description: A method of the Queen class that overrides the setPosition method of the Solider class the purpose of which is to set the queen's position. It was chosen to override the setPosition moethod in order to update the position of theQueen's Rook and Bishop aswell.
[<-] const Position& newPosition: the Position to be assigned to the Queen (and its Rook & Bishop).
[->] X (void)
*/
void Queen::setPosition(const Position& newPosition)
{
	this->_pRook->setPosition(newPosition);
	this->_pBishop->setPosition(newPosition);
	Solider::setPosition(newPosition);
}

/*
[?] Description: A destructor for the Queen class.
[<-] X (none)
[->] X
*/
Queen::~Queen()
{
	// deleting the allocated memory for the rook & bishop.
	delete this->_pRook;
	delete this->_pBishop;
}
