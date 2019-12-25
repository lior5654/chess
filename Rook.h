#pragma once
#include "Solider.h"

class Rook : public Solider
{
public:
	Rook(Position position, Color color);
	MoveCode virtual canMove(const Position& dest, const Board& gameBoard);
};

