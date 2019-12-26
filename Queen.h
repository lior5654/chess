#pragma once
#include "Board.h"


class Queen : public Solider
{
public:
	Queen(const Position& position, const Color& color, const Board* pGameBoard);
	virtual bool canMove(const Position& dest) override;
};

