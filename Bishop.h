#pragma once
#include "Solider.h"
class Bishop : virtual public Solider
{
public:
	Bishop();
	Bishop(const Position& position, const Color& color);
	virtual bool canMove(const Position& dest, const Board& gameBoard) override;
};

