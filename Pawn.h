#pragma once
#include "Board.h"
#include "Solider.h"

class Pawn : public Solider
{
public:
	
	Pawn(Position position, Color color, const Board* pGameBoard);
	virtual bool canMove(const Position& dest) override;
private:
	bool _moved;
	bool haveSameColor(Solider* otherSolider);
	Position addOneCol(Position& pos);
};

