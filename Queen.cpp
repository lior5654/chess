#include "Queen.h"

Queen::Queen(const Position& position, const Color& color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard)
{
}
bool Queen::canMove(const Position& dest)
{
	bool output = true;
	unsigned int start = 0;  // start y or x
	unsigned int end = 0;  // end y or x
	unsigned int step = 0;  // if move up and down
	bool moveColumn = false;


	Position myPos = this->position();
	// check if move vertical
	if (!(myPos - dest) && !(myPos || dest))
	{
		output =  false;
	}
	else
	{
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
		for (int i = start; i < end && output; i += step)
		{
			if (moveColumn)
			{
				currentPos.setColumn(currentPos.column() + step);
				if ((*this->pBoard())[currentPos] != nullptr)
				{
					output = false;
				}
			}
			else
			{
				currentPos.setRow(currentPos.row() + step);

				if ((*this->pBoard())[currentPos] != nullptr)
				{
					output = false;
				}
			}
		}

		if (output)
		{
			return true;
		}
		else
		{
			unsigned int i = 0;
			int posOffset = 0;
			if (this->position() / dest)
			{
				posOffset = ((this->position()).column() > this->position().column()) ? -8 : 8 + ((this->position()).row() > this->position().row()) ? -1 : 1;
				for (unsigned int i = (unsigned int)(this->position()) + posOffset; i != (unsigned int)dest - posOffset; i += posOffset)
				{
					if ((*this->pBoard())[i] != nullptr)
					{
						return false;
					}
				}
				return true;
			}
			return false;
		}
	}
	
}


