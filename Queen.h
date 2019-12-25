#pragma once
#include "Solider.h"
class Queen : virtual Rook, Bishop
{
public:
	Queen(const Position& position, const Color& color);
	virtual bool canMove(const Position& dest, const Board& gameBoard) const override;
};

