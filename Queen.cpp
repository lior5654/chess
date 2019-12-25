#include "Queen.h"

Queen::Queen(const Position& position, const Color& color) :
	Rook::(position, color), Bishop::(position, color)
{

}
bool Queen::canMove(const Position& dest, const Board& gameBoard) const
{
	return Rook::canMove(dest, gameBoard) || Bishop::canMove(dest, gameBoard);
}