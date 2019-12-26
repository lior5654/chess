#pragma once
#include "Solider.h"
class Solider;
#include <cmath>

class King : public Solider
{
public:
	King(const Position& position, const Color& color, const Board* pGameBoard);
	virtual bool canMove(const Position& dest) override;
	bool isAlerted(void);
};

