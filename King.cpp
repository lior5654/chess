#include "King.h"

King::King(const Position& position, const Color& color) :
	Solider(position, color)
{

}
bool King::canMove(const Position& dest, const Board& gameBoard) const
{
	return (this->position() - dest) == 1 || (this->position() || dest) == 1;
}
bool King::isAlerted(const Board& gameBoard)
{
	unsigned i = 0;
	for (i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
	{
		if (gameBoard[i] != nullptr && gameBoard[i]->color() != this->color() && gameBoard[i]->canMove(this->position(), gameBoard))
		{
			return true;
		}
	}
	return false;
}