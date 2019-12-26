#pragma once

#include "Position.h"
#include "enums.h"
#include "Board.h"
class Board;
class Solider
{
public:
	Solider(const Position& position, const Color& color, const Board* pGameBoard);

	virtual bool canMove(const Position& dest) = 0;
	Color color(void) const;
	Position position(void) const;
	const Board* pBoard(void) const;
	void setColor(Color newColor);
	void setPosition(Position newPosition);


protected:
	Color _color;
	Position _position;
	const Board* _pBoard;
};

