#pragma once

#include "Position.h"
#include "Game.h"  // color
class Solider
{
	Solider(const Position position, Color color);

	bool virtual canMove(const Position dest) = 0;
	char virtual GetRepresentation() = 0;

protected:
	Color color;
	Position position;
};

