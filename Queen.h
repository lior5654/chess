#pragma once
#include "Solider.h"

// TO DO: add the other Solider and fix diamond problem
class Queen : public Solider
{
public:
	Queen(const Position& position, const Color& color);
	virtual bool canMove(const Position& dest, const Board& gameBoard) override;
};

