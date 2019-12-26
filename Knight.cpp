#include "Knight.h"

Knight::Knight(Position position, Color color) : Solider(position, color)
{

}

bool Knight::canMove(const Position& dest, const Board& gameBoard)
{
	Position myPosition = this->position();
	if ((myPosition || dest) == 2 && (myPosition - dest) == 1)
	{
		return true;
	}
	else if ((myPosition - dest) == 2 && (myPosition || dest) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
