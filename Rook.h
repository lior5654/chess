#pragma once
#include "Solider.h"
class Rook :
	public Solider
{
public:
	Rook(Position position, Color color);
	bool virtual canMove(Position& dest) override;
	char virtual GetRepresentation() override;
};

