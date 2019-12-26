#pragma once
#include "Solider.h"

class Solider;
class Queen : public Rook, public Bishop
{
public:
	Queen(const Position& position, const Color& color, const Board* pGameBoard);
	virtual bool canMove(const Position& dest) override;
};

