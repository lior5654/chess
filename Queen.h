#pragma once
#include "Solider.h"
class Queen : public Solider
{
public:
	Queen(Position position, Color color);
	bool virtual canMove(Position& dest) override;
	char virtual getRepresentation() override;
};

