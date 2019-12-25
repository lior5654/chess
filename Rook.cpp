#include "Rook.h"

// finish Rook class

Rook::Rook(const Position& position, const Color& color) : Solider(position, color)
{

}

bool Rook::canMove(const Position& dest, const Board& gameBoard) const
{
	unsigned int start = 0;  // start y or x
	unsigned int end = 0;  // end y or x
	unsigned int step = 0;  // if move up and down
	bool moveColumn = false;

	// check if move vertical
	if (dest.column() != this->position().column() && dest.row() != this->position().row())
	{
		return false;
	}

	// if move by col
	if (dest.column() != this->position().column())
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
		// if have player there
		return false;
	}

	return true;
}