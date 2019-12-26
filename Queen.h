#pragma once
#include "Solider.h"
#include "Rook.h"
#include "Bishop.h"

class Queen : public Rook, public Bishop
{
public:
	Queen(const Position& position, const Color& color);
	virtual bool canMove(const Position& dest, const Board& gameBoard) override;
};

