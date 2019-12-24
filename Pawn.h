#pragma once
#include "Solider.h"
class Pawn : public Solider
{
public:
	
	Pawn(Position position, Color color);
	bool virtual canMove(Position& dest) override;
	char virtual getRepresentation() override;
private:
	bool moved;
};

