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


	// check if move back
	if (isGoingBack(myPos, dest, this->color()))
	{
		return false;
	}


	if (((myPos || dest) <= maxMove) && ((myPos - dest) == 0))
	{
		// if have Solider In the way
		if (!(this->_moved))
		{
			
			posForward(tempPos, this->color());
			// if move by two
			movePlaceSolider = (*this->pBoard())[tempPos];
			if ((myPos || dest) == 2)
			{
				if ((*this->pBoard())[tempPos] != nullptr)  // check if have Solider in the way
				{
					return false;
				}

				posForward(tempPos, this->color());
				movePlaceSolider = (*this->pBoard())[tempPos];
			}

			if (movePlaceSolider == nullptr || canKillSolider(movePlaceSolider))  // if have target and if it not the same color
			{

				this->_moved = true;
				return true;
			}
		}
		else
		{
			this->_moved = true;
			return true;
		}
	}
	
	// if kill 
	if ((myPos || dest) == 1 && (myPos - dest) == 1)
	{
		// check if not have same color Solider there
		if (canKillSolider((*this->pBoard())[dest]))
		{

			this->_moved = true;
			return true;
		}
	}

	return false;
}

bool Pawn::canKillSolider(const Solider* otherSolider)
{
	if (otherSolider == nullptr)
	{
		return false;
	}
	return this->color() != otherSolider->color();
}

Position Pawn::posForward(Position& pos, Color color)
{
	if (color == WHITE)
	{
		pos.setRow(pos.row() + 1);
	}
	else
	{
		pos.setRow(pos.row() - 1);
	}
	return pos;
}

bool Pawn::isGoingBack(const Position& origin, const Position& dest, const Color color)
{
	bool returnBool = false;
	if (color == WHITE)
	{
		returnBool = origin > dest;
	}
	else
	{
		returnBool = origin < dest;
	}
	return returnBool;
}
