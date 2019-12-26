#pragma once
#include "Solider.h"
#include <cmath>
class King : public Solider
{
public:
	King(const Position& position, const Color& color);
	virtual bool canMove(const Position& dest, const Board& gameBoard) override;
	bool isAlerted(const Board& gameBoard);
};

