#pragma once
#include <stdlib.h>     /* abs */
#include "Solider.h"

class Solider;
class Knight : public Solider
{
public:
	Knight(const Position& position, const Color& color, const Board* pGameBoard);
	virtual bool canMove(const Position& dest) override;
};

