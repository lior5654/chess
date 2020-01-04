/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Pawn.cpp
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/

// INCLUDES
#include "Pawn.h"

/*
[?] Description: A constructor for the Pawn class.
[<-] const Position& position: An initial position for the Pawn.
[<-] const Color& color: The Pawn's color.
[<-] const Board* pGameBoard: a pointer to the board the Pawn is in
[->] X
*/
Pawn::Pawn(Position position, Color color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard), _moved(false)
{

}

/*
[?] Description: A method of the Pawn class that overrides the canMove abstract method of the Solider class the purpose of which is to test whether or not the Pawn at its current state can move to a given destination.
[<-] const Position& dest: the destination to test whether or not the Pawn in its current state can move to.
[->] bool: a boolean representation of whether or not the Pawn can move to the given destination.
*/
bool Pawn::canMove(const Position& dest)
{
	// check if move one
	Position myPos = this->position();
	Position tempPos = this->position();
	Solider* movePlaceSolider = nullptr;
	unsigned int maxMove = _moved ? 1 : 2;
	unsigned int moveDiss = (myPos || dest);
	unsigned int i = 0;  // loop variable
	// check if move back
	if (isGoingBack(myPos, dest, this->color()))
	{
		return false;
	}

	
	if ((moveDiss <= maxMove) && ((myPos - dest) == 0))  // if the move distance is less than the max distance allowed and the horizontal move distance is 0
	{
		// if have Solider In the way
		for (i = 0; i < moveDiss; i++)
		{
			posForward(tempPos, this->color());
			movePlaceSolider = (*this->pBoard())[tempPos];
			if (movePlaceSolider != nullptr)
			{
				return false;
			}
		}
		this->_moved = true;
		return true;
	}
	
	// if kill 
	if ((myPos || dest) == 1 && (myPos - dest) == 1 && (*this->pBoard())[dest] != nullptr)
	{
		this->_moved = true;
		return true;
	}
	return false;
}

/*
[?] Description: A static method of the Pawn class that performs a "forward" move based on a color, namely move a location by one unit "forward" based on what forward means to a player the color of which is given.
[<-] Position& pos: The position to perform a "forward" operation on.
[<-] const Color& color: the color to relate the "forwardness" of the move to.
[->] X (void)
*/
void Pawn::posForward(Position& pos, const Color& color)
{
	if (color == Color::WHITE)
	{
		pos.setY(pos.y() + 1);
	}
	else
	{
		pos.setY(pos.y() - 1);
	}
}

/*
[?] Description: A static method of the Pawn class that returns a boolean representation of whether or not a move from a given origin to a given destination is considered to be "back" in relation to a player whose color is given.
[<-] const Position& origin: the origin of the move to be tested.
[<-] const Position& dest: the destination of the move to be tested.
[<-] const Color& color: the color of the player responsible of the move. 
[->] bool returnBool: a boolean representation of whether or not a move from the given origin to the given destination is considered to be "back" in relation to the given player color.
*/
bool Pawn::isGoingBack(const Position& origin, const Position& dest, const Color& color)
{
	bool returnBool = false;
	if (color == Color::WHITE)
	{
		returnBool = origin > dest;
	}
	else
	{
		returnBool = origin < dest;
	}
	return returnBool;
}
