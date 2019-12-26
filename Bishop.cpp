#include "Bishop.h"
Bishop::Bishop(const Position& position, const Color& color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard)
{

}
bool Bishop::canMove(const Position& dest)
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
