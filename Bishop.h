#pragma once
#include "Solider.h"

class Soldier;
class Bishop : virtual public Solider
{
public:
	Bishop();
	Bishop(const Position& position, const Color& color, const Board* pGameBoard);
	virtual bool canMove(const Position& dest) override;
};

