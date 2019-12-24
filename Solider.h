#pragma once

#include "Position.h"
#include "Game.h"  // color
#include "Board.h"

class Solider
{
public:
	Solider(Position position, Color color);
	Solider();

	bool virtual canMove(Position& dest, Board& theBoard) = 0;
	char virtual getRepresentation() = 0;

protected:
	Color color;
	Position position;
};

