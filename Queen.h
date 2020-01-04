/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Queen.h
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/
#pragma once

// INCLUDES
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
	virtual void setPosition(const Position& newPosition) override;
private:
	Rook* _pRook;
	Bishop* _pBishop;
};

