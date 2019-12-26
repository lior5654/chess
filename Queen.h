#pragma once
#include "Rook.h"
#include "Bishop.h"
#include "Board.h"
class Rook;
class Bishop;
class Queen : public Solider
{
public:
	Queen(const Position& position, const Color& color, const Board* pGameBoard);
	virtual ~Queen();
	virtual bool canMove(const Position& dest) override;
	virtual void setPosition(Position newPosition) override;
private:
	Rook* _rook;
	Bishop* _bishop;
};

