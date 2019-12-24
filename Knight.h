#pragma once
#include "Solider.h"
class Knight : public Solider
{
public:
	Knight(Position position, Color color);
	bool virtual canMove(Position& dest, Board& theBoard) override;
	char virtual getRepresentation() override;
};

