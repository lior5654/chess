#pragma once
#include "Solider.h"
class Bishop :
	public Solider
{
public:
	Bishop(Position position, Color color);
	bool virtual canMove(Position& dest) override;
	char virtual GetRepresentation() override;
};

