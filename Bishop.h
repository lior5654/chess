#pragma once
#include "Solider.h"
class Bishop : public Solider
{
public:
	Bishop(const Position& position, const Color& color);
	virtual bool canMove(const Position& dest, const Board& gameBoard) const override;
};

