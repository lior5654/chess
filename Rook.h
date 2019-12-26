#pragma once
#include "Solider.h"
#include "Board.h"
#include "Bishop.h"
//class Queen;

class Rook : virtual public Solider
{
public:
	Rook();
	Rook(const Position& position, const Color& color);
	virtual bool canMove(const Position& dest, const Board& gameBoard) override;
};

//class Queen : public Rook, public Bishop
//{
//public:
//	Queen(const Position& position, const Color& color);
//	virtual bool canMove(const Position& dest, const Board& gameBoard) override;
//};

