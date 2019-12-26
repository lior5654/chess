#pragma once
#include "Solider.h"

class Solider;
class Rook : virtual public Solider
{
public:
	Rook(const Position& position, const Color& color, const Board* pGameBoard);
	virtual bool canMove(const Position& dest) override;
};
