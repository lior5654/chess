#pragma once

#include "Position.h"
#include "enums.h"
#include "Board.h"

class Board;
class Solider
{
public:
	Solider();
	Solider(const Position& position, const Color& color);

	virtual bool canMove(const Position& dest, const Board& gameBoard) = 0;
	Color color() const;
	Position position() const;
	void setColor(Color newColor);
	void setPosition(Position newPosition);


protected:
	Color _color;
	Position _position;
};

