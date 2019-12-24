#pragma once

#include "Board.h"
#include "GraphicsPipe.h"
#include <iostream>
#include "enums.h"
#define INITIAL_BOARD "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR"
#define VALID_REPLY_LENGTH 4

class Game
{
public:
	Game();
	void update();
	//bool isGameOver();
private:
	Board _gameBoard;
	GraphicsPipe _gp;
	std::string _lastReplyFromGraphics;
};

