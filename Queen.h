#pragma once
#include "Solider.h"
class Queen : public Solider
{
public:
	Queen(Position position, Color color);
	MoveCode virtual canMove(const Position& dest, const Board& gameBoard);
};

