#pragma once
#include "Solider.h"
class King : public Solider
{
public:
	King(Position position, Color color);
	virtual bool canMove(const Position& dest, const Board& gameBoard) const override;
};

