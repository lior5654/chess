#include "King.h"

King::King(const Position& position, const Color& color) :
	Solider(position, color)
{

}
bool King::canMove(const Position& dest, const Board& gameBoard)
{
	return (abs((int)this->position().column() - (int)dest.column()) == 1 || abs((int)this->position().row() - (int)dest.row()) == 1);
}
bool King::isAlerted(const Board& gameBoard)
{
	for (auto solider : gameBoard)
	{
		if (solider != nullptr && solider->color() != this->color() && solider->canMove(this->position()))
		{
			return true;
		}
	}
	return false;
}