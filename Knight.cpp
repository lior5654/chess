/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Knight.cpp
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/

// INCLUDES
#include "Knight.h"

/*
[?] Description: A constructor for the Knight class.
[<-] const Position& position: An initial position for the Knight.
[<-] const Color& color: The Knight's color.
[<-] const Board* pGameBoard: a pointer to the board the Knight is in
[->] X
*/
Knight::Knight(const Position& position, const Color& color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard)
{

}

/*
[?] Description: A method of the Knight class that overrides the canMove abstract method of the Solider class the purpose of which is to test whether or not the Knight at its current state can move to a given destination.
[<-] const Position& dest: the destination to test whether or not the Knight in its current state can move to.
[->] bool: a boolean representation of whether or not the Knight can move to the given destination.
*/
bool Knight::canMove(const Position& dest)
{
	return ((this->position() || dest) == KNIGHT_SECOND_AXIS_DISTANCE && (this->position() - dest) == KNIGHT_FIRST_AXIS_DISTANCE) ||
		   ((this->position() - dest) == KNIGHT_SECOND_AXIS_DISTANCE && (this->position() || dest) == KNIGHT_FIRST_AXIS_DISTANCE);
}
