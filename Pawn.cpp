#include "Pawn.h"

Pawn::Pawn(Position position, Color color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard)
{

}

bool Pawn::canMove(const Position& dest)
{
	// check if move one
	Position myPos = this->position();
	Position tempPos = this->position();
	Solider* movePlaceSolider = nullptr;
	unsigned int maxMove = _moved ? 1 : 2;

	//this->_moved = true;

	if (((myPos || dest) <= maxMove) && ((myPos - dest) == 0))
	{
		// if have Solider In the way
		if (this->_moved)
		{
			
			addOneCol(tempPos);
			// if move by two
			movePlaceSolider = (*this->pBoard())[tempPos];
			if ((myPos || dest) == 2)
			{
				if ((*this->pBoard())[tempPos] != nullptr)  // check if have Solider in the way
				{
					return false;
				}

				addOneCol(tempPos);
				movePlaceSolider = (*this->pBoard())[tempPos];
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
		if (!haveSameColor((*this->pBoard())[dest]))
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
