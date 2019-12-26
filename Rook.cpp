#include "Rook.h"


Rook::Rook(const Position& position, const Color& color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard)
{

}

bool Rook::canMove(const Position& dest)
{
	unsigned int i = 0;
	int posOffset = 0;
	if (!(this->position() - dest))
	{
		posOffset = ((this->position()).row() > dest.row()) ? -8 : 8;
	}
	else if (!(this->position() || dest))
	{
		posOffset = ((this->position()).column() > dest.column()) ? -1 : 1;
	}
	else
	{
		return false;
	}
	for (unsigned int i = (unsigned int)(this->position()) + posOffset; (posOffset > 0) && i <= (unsigned int)dest - posOffset || (posOffset < 0) && i >= (unsigned int)dest - posOffset; i += posOffset)
	{
		if ((*this->pBoard())[i] != nullptr)
		{
			return false;
		}
	}
	return true;
}