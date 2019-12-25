#pragma once
#include "Solider.h"
class Knight : public Solider
{
public:
	Knight(Position position, Color color);
	MoveCode virtual canMove(const Position& dest, const Board& gameBoard);
};

