#pragma once
#include "Solider.h"
class Pawn : public Solider
{
public:
	
	Pawn(Position position, Color color);
	virtual bool canMove(const Position& dest, const Board& gameBoard) override;
private:
	bool _moved;
};

