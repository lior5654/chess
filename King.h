#pragma once
#include "Solider.h"
class King : public Solider
{
public:
	King(Position position, Color color);
	MoveCode virtual canMove(const Position& dest, const Board& gameBoard);
};

