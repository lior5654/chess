#include "Knight.h"

Knight::Knight(const Position& position, const Color& color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard)
{

}

bool Knight::canMove(const Position& dest)
{
	return ((this->position() || dest) == 2 && (this->position() - dest) == 1) ||
		   ((this->position() - dest) == 2 && (this->position() || dest) == 1);
}
