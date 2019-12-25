#include "Knight.h"

Knight::Knight(Position position, Color color) : Solider(position, color)
{

}

bool Knight::canMove(const Position& dest, const Board& gameBoard) const
{
	Position myPosition = this->position();
	if (abs( ((int)myPosition.column() - (int)dest.column())) == 2)
	{

	}
	return false;
}
