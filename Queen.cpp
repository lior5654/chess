#include "Queen.h"

Queen::Queen(const Position& position, const Color& color) : Solider(position, color)
{

}
bool Queen::canMove(const Position& dest, const Board& gameBoard)
{
	return Rook::canMove(dest, gameBoard) || Bishop::canMove(dest, gameBoard);
}