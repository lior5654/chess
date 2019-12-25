#pragma once
#include "Solider.h"
class Pawn : public Solider
{
public:
	
	Pawn(Position position, Color color);
	MoveCode virtual canMove(const Position& dest, const Board& gameBoard);
private:
	bool _moved;
};

