#pragma once
#include "Solider.h"

class Rook : public Solider
{
public:
	Rook(Position position, Color color);
	bool virtual canMove(Position& dest, Board& theBoard) override;
	char virtual getRepresentation() override;
};

