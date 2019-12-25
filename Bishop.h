#pragma once
#include "Solider.h"
class Bishop : public Solider
{
public:
	Bishop(Position position, Color color);
	MoveCode virtual canMove(const Position& dest, const Board& gameBoard);
};

