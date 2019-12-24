#pragma once
#include "Solider.h"
class King : public Solider
{
public:
	King(Position position, Color color);
	bool virtual canMove(Position& dest, Board& theBoard) override;
	char virtual getRepresentation() override;
};

