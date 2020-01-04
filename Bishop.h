/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Bishop.h
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galan // JacobGalm
***************************************************************************/
#pragma once

// INCLUDES
#include "Board.h"
#include "Solider.h"

class Bishop : public Solider
{
public:
	Bishop();
	Bishop(const Position& position, const Color& color, const Board* pGameBoard);
	virtual bool canMove(const Position& dest) override;
};

