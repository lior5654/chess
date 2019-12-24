#pragma once
#include "Solider.h"
class Bishop : public Solider
{
public:
	Bishop(Position position, Color color);
	bool virtual canMove(Position& dest, Board& theBoard) override;
	char virtual getRepresentation() override;
};

