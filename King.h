/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: King.h
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/
#pragma once

// INCLUDES
#include "Board.h"
#include "Solider.h"
#include <cmath>

// DEFINE CONSTANTS
#define MAX_KING_TRAVEL_OFFSET 1

class King : public Solider
{
public:
	King(const Position& position, const Color& color, const Board* pGameBoard);
	virtual bool canMove(const Position& dest) override;
};

