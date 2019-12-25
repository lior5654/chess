#pragma once
#include "Solider.h"

class Rook : virtual Solider
{
public:
	Rook(const Position& position, const Color& color);
	virtual bool canMove(const Position& dest, const Board& gameBoard) const override;
};

