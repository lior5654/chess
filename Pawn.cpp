#include "Pawn.h"

Pawn::Pawn(Position position, Color color) : Solider(position, color)
{

}

bool Pawn::canMove(const Position& dest, const Board& gameBoard)
{
	// check if move one
	Position myPos = this->position();
	Position tempPos = this->position();
	Solider* movePlaceSolider;
	unsigned int maxMove = _moved ? 1 : 2;

	//this->_moved = true;

	if (((myPos || dest) <= maxMove) && ((myPos - dest) == 0))
	{
		// if have Solider In the way
		if (this->_moved)
		{
			
			addOneCol(tempPos);
			// if move by two
			movePlaceSolider = gameBoard[tempPos];
			if ((myPos || dest) == 2)
			{
				if (gameBoard[tempPos] != nullptr)  // check if have Solider in the way
				{
					return false;
				}

				addOneCol(tempPos);
				movePlaceSolider = gameBoard[tempPos];
			}

			if (!haveSameColor(movePlaceSolider))  // if have target and if it not the same color
			{
				this->_moved = true;
				return true;
			}
		}
		else
		{
			return true;
		}
	}
	
	if ((myPos || dest) == 1 && (myPos - dest) == 1)
	{
		// check if move back
		if (myPos.column() > dest.column())
		{
			return false;
		}

		// check if not have same color Solider there
		if (!haveSameColor(gameBoard[dest]))
		{
			this->_moved = true;
			return true;
		}
	}
	// check if have kill enemy

	return false;
}

bool Pawn::haveSameColor(Solider* otherSolider)
{
	if (otherSolider == nullptr)
	{
		return false;
	}
	return this->color() == otherSolider->color();
}

Position Pawn::addOneCol(Position& pos)
{
	pos.setColumn(pos.column() + 1);
	return pos;
}
