#include "Bishop.h"

Bishop::Bishop()
{

}

Bishop::Bishop(const Position& position, const Color& color) : Solider(position, color)
{

}

bool Bishop::canMove(const Position& dest, const Board& gameBoard)
{
	return false;
}
