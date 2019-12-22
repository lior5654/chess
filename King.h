#pragma once
#include "Solider.h"
class King :
	public Solider
{
public:
	King(Position position, Color color);
	bool virtual canMove(Position& dest) override;
	char virtual GetRepresentation() override;
};

