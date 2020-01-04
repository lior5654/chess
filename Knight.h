/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Knight.h
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/
#pragma once

// INLCUDES
#include "Board.h"
#include "Solider.h"
#include <cmath>

// DEFINE CONSTANTS
#define KNIGHT_FIRST_AXIS_DISTANCE 1
#define KNIGHT_SECOND_AXIS_DISTANCE 2

class Knight : public Solider
{
public:
	Knight(const Position& position, const Color& color, const Board* pGameBoard);
	virtual bool canMove(const Position& dest) override;
};

