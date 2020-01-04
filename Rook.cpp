/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Rook.cpp
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/

// INCLUDES
#include "Rook.h"

/*
[?] Description: A constructor for the Rook class.
[<-] const Position& position: An initial position for the Rook.
[<-] const Color& color: The Rook's color.
[<-] const Board* pGameBoard: a pointer to the board the Rook is in
[->] X
*/
Rook::Rook(const Position& position, const Color& color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard)
{

}

/*
[?] Description: A method of the Rook class that overrides the canMove abstract method of the Solider class the purpose of which is to test whether or not the Rook at its current state can move to a given destination.
[<-] const Position& dest: the destination to test whether or not the Rook in its current state can move to.
[->] bool: a boolean representation of whether or not the Rook can move to the given destination.
*/
bool Rook::canMove(const Position& dest)
{
	unsigned int i = 0;
	int posOffset = 0;
	// calculating the posOffset required to perform the move and consenquently checking if the move utilizes a single axis (if not, returning false)
	// see the code of the Bishop class for a definition of the term "posOffset". Same meaning in this case as well.
	if (!(this->position() - dest))  // y axis utilization only
	{
		posOffset = ((this->position()).y() > dest.y()) ? -BOARD_SIZE : BOARD_SIZE;
	}
	else if (!(this->position() || dest))  // x axis utilization only
	{
		posOffset = ((this->position()).x() > dest.x()) ? -1 : 1;
	}
	else
	{
		return false;
	}

	// making sure there are no soliders in the middle of the track by iterating over all of the none edge squares in the path of the move using the calculated posOffset
	for (unsigned int i = (unsigned int)(this->position()) + posOffset; (posOffset > 0) && i <= (unsigned int)dest - posOffset || (posOffset < 0) && i >= (unsigned int)dest - posOffset; i += posOffset)
	{
		if ((*this->pBoard())[i] != nullptr)  // soldier found
		{
			return false;
		}
	}
	return true;
}