#pragma once

#include "Position.h"
#include "Game.h"  // color
class Solider
{
public:
	Solider(Position position, Color color);

	bool virtual canMove(Position& dest) = 0;
	char virtual GetRepresentation() = 0;

protected:
	Color color;
	Position position;
};

