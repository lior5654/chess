#include "King.h"

King::King(const Position& position, const Color& color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard)
{

}
bool King::canMove(const Position& dest)
{
	return (this->position() - dest) == 1 && !(this->position() || dest) || (this->position() || dest) == 1 && !(this->position() - dest);
}