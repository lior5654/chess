#pragma once
#include "Solider.h"

class Rook : virtual public Solider
{
public:
	Rook();
	Rook(const Position& position, const Color& color);
	virtual bool canMove(const Position& dest, const Board& gameBoard) override;
};

