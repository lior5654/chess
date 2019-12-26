#include "King.h"

King::King(const Position& position, const Color& color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard)
{

}
bool King::canMove(const Position& dest)
{
	return (this->position() - dest) == 1 || (this->position() || dest) == 1;
}
bool King::isAlerted(void)
{
	unsigned int i = 0;
	for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
	{
		if ((*(this->pBoard()))[i] == nullptr)
		{
			continue;
		}
		if ((*(this->pBoard()))[i]->color() != this->color() && (*(this->pBoard()))[i]->canMove(this->position()))
		{
			return true;
		}
	}
	return false;
}