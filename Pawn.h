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
	bool canKillSolider(const Solider* otherSolider);
	static Position posForward(Position& pos, Color color);
	static bool isGoingBack(const Position& origin, const Position& dest, const Color color);
};

