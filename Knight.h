#pragma once
#include "Solider.h"
class Knight : public Solider
{
public:
	Knight(Position position, Color color);
	virtual bool canMove(const Position& dest, const Board& gameBoard) const override;
};

