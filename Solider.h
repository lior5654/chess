/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Solider.h
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/
#pragma once

// INCLUDES
#include "Position.h"
#include "enums.h"

using chessEnums::Color;
using chessEnums::MoveCode;
class Board;
class Solider
{
public:
	Solider(const Position& position, const Color& color, const Board* pGameBoard);
	virtual ~Solider();
	virtual bool canMove(const Position& dest) = 0;
	Color color(void) const;
	Position position(void) const;
	const Board* pBoard(void) const;
	void setColor(const Color& newColor);
	virtual void setPosition(const Position& newPosition);


protected:
	Color _color;
	Position _position;
	const Board* _pBoard;
};

