#pragma once
#include "Board.h"
#include "Solider.h"

class Board;
class Bishop : public Solider
{
public:
	Bishop();
	Bishop(const Position& position, const Color& color, const Board* pGameBoard);
	virtual bool canMove(const Position& dest) override;
};

