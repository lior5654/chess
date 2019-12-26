#include "Bishop.h"

Bishop::Bishop(const Position& position, const Color& color) :
	Solider(position, color)
{

}
bool Bishop::canMove(const Position& dest, const Board& gameBoard) const
{
	unsigned int i = 0;
	int posOffset = 0;
	if (this->position() / dest)
	{
		posOffset = ((this->position()).column() > this->position().column()) ? -8 : 8 + ((this->position()).row() > this->position().row()) ? -1 : 1;
		for (unsigned int i = (unsigned int)(this->position()) + posOffset; i += posOffset; i != (unsigned int)dest - posOffset)
		{
			if (gameBoard[i] != nullptr)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}