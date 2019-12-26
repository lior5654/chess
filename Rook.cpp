#include "Rook.h"

// finish Rook class



Rook::Rook()
{
}

Rook::Rook(const Position& position, const Color& color) : Solider(position, color)
{

}

bool Rook::canMove(const Position& dest, const Board& gameBoard)
{
	unsigned int start = 0;  // start y or x
	unsigned int end = 0;  // end y or x
	unsigned int step = 0;  // if move up and down
	bool moveColumn = false;


	Position myPos = this->position();
	// check if move vertical
	if (!(myPos - dest) && !(myPos || dest))
	{
		return false;
	}

	// if move by col
	if ((myPos || dest) == 0)
	{
		start = this->position().column();
		end = dest.column();
		moveColumn = true;
	}
	else  // if move by raw
	{
		start = this->position().row();
		end = dest.row();
		moveColumn = false;
	}
	step = end - start < 0 ? 1 : -1;  // if moving down or up

	// get the wanted Axis for check if ther is any Soliders in the way
	Position currentPos = Position(this->position());
	// loop and check if have Solider in the way check 
	for (int i = start; i < end; i += step)
	{
		if (moveColumn)
		{
			currentPos.setColumn(currentPos.column() + step);
			if (gameBoard[currentPos] != nullptr)
			{
				return false;
			}
		}
		else
		{
			currentPos.setRow(currentPos.row() + step);

			if (gameBoard[currentPos] != nullptr)
			{
				return false;
			}
		}
	}
	
	
	return true;
}

Queen::Queen(const Position& position, const Color& color) : Solider(position, color)
{

}
bool Queen::canMove(const Position& dest, const Board& gameBoard)
{
	return Rook::canMove(dest, gameBoard) || Bishop::canMove(dest, gameBoard);
}