/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: King.cpp
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/

// INCLUDES
#include "King.h"

/*
[?] Description: A constructor for the King class.
[<-] const Position& position: An initial position for the King.
[<-] const Color& color: The King's color.
[<-] const Board* pGameBoard: a pointer to the board the King is in
[->] X
*/
King::King(const Position& position, const Color& color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard)
{

}

/*
[?] Description: A method of the King class that overrides the canMove abstract method of the Solider class the purpose of which is to test whether or not the King at its current state can move to a given destination.
[<-] const Position& dest: the destination to test whether or not the King in its current state can move to.
[->] bool: a boolean representation of whether or not the King can move to the given destination.
*/
bool King::canMove(const Position& dest)
{
	return (this->position() - dest) <= MAX_KING_TRAVEL_OFFSET && (this->position() || dest) <= MAX_KING_TRAVEL_OFFSET;
}
