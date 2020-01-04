/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Game.h
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galan // JacobGalm
***************************************************************************/
#pragma once

// INCLUDES
#include "Board.h"
#include "GraphicsPipe.h"
#include <iostream>
#include "enums.h"

using chessEnums::Color;
using chessEnums::MoveCode;
// DEFINE CONSTANTS
#define INITIAL_BOARD "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"
#define VALID_REPLY_LENGTH 4
#pragma comment(lib, "winmm.lib")

class Game
{
public:
	Game();
	~Game();
	bool update();
private:
	Board* _pGameBoard;
	GraphicsPipe* _pGraphicsPipe;
	bool _gameEnd;
};

