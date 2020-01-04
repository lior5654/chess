/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Bishop.cpp
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/

// INCLUDES
#include "Bishop.h"

/*
[?] Description: A constructor for the Bishop class.
[<-] const Position& position: An initial position for the Bishop.
[<-] const Color& color: The Bishop's color.
[<-] const Board* pGameBoard: a pointer to the board the Bishop is in
[->] X
*/
Bishop::Bishop(const Position& position, const Color& color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard)
{

}

/*
[?] Description: A method of the Bishop class that overrides the canMove abstract method of the Solider class the purpose of which is to test whether or not the Bishop at its current state can move to a given destination.
[<-] const Position& dest: the destination to test whether or not the Bishop in its current state can move to.
[->] bool: a boolean representation of whether or not the Bishop can move to the given destination.
*/
bool Bishop::canMove(const Position& dest)
{
	unsigned int i = 0;
	int posOffset = 0;
	if (this->position() / dest)  // making sure that the bishop is in the same diagonal as the dest
	{
		posOffset = (((this->position()).x() > dest.x()) ? -1 : 1) + (((this->position()).y() > dest.y()) ? -BOARD_SIZE : BOARD_SIZE);  // calculating the position offset added to the bishop's location at every substep he takes (moving 1 square) (which trivially stays constant)
		for (unsigned int i = (unsigned int)(this->position()) + posOffset; (posOffset > 0) && i <= (unsigned int)dest - posOffset || (posOffset < 0) && i >= (unsigned int)dest - posOffset; i += posOffset)  // making sure that there are no soliders in the bishop's path (except the goal)
		{
			if ((*this->pBoard())[i] != nullptr)  // solider found
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
