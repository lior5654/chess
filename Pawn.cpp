#include "Pawn.h"

Pawn::Pawn(Position position, Color color) : Solider(position, color)
{

}

bool Pawn::canMove(const Position& dest, const Board& gameBoard)
{
	// check if move one
	Position myPos = this->position();
	Position tempPos = this->position();

	unsigned int maxMove = _moved ? 1 : 2;

	// TO DO
	//this->_moved = true;

	if ((myPos || dest) <= maxMove)
	{
		// if can move
		for (int i = 0; i < maxMove; i++)
		{
			// if have Solider in the way
		}
	}
	
	// check if have kill enemy 

	return false;
}
