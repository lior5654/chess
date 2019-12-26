#pragma once
#include "Board.h"
#include "Solider.h"
#include <cmath>

class Knight : public Solider
{
public:
	Knight(const Position& position, const Color& color, const Board* pGameBoard);
	virtual bool canMove(const Position& dest) override;
};

