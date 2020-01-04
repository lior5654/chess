/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Pawn.h
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/
#pragma once

// INCLUDES
#include "Board.h"
#include "Solider.h"

class Pawn : public Solider
{
public:
	
	Pawn(Position position, Color color, const Board* pGameBoard);
	virtual bool canMove(const Position& dest) override;
private:
	bool _moved;
	static void posForward(Position& pos, const Color& color);
	static bool isGoingBack(const Position& origin, const Position& dest, const Color& color);
};

