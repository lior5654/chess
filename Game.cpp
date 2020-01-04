/**************************************************************************
@ Project: Magshimim C++ Course Semester 1 Lesson 7-8 Chess Project
@ File: Game.cpp
@ Version: 1.0
@ Made By: Lior Yehezkely // lior5654 // Th3Wh1t3Kn19ht & Jacob Galam // JacobGalam
***************************************************************************/

// INCLUDES
#include "Game.h"

/*
[?] Description: A constructor for the Game class.
[<-] X (none)
[->] X
*/
Game::Game()
{
	this->_pGameBoard = new Board(INITIAL_BOARD);
	this->_gameEnd = false;
	char initMessageToSend[MSG_SIZE] = INITIAL_BOARD;
	this->_pGraphicsPipe = new GraphicsPipe(initMessageToSend);
	PlaySound("gameSong.wav", NULL, SND_LOOP | SND_ASYNC);

}

/*
[?] Description: A deconstructor for the Game class.
[<-] X (none)
[->] X
*/
Game::~Game()
{
	delete this->_pGameBoard;
	delete this->_pGraphicsPipe;
}

/*
[?] Description: A method of the game class that plays a "turn"
[<-] X (none)
[->] bool: a boolean representation of whether or not the game has not ended.
*/
bool Game::update()
{

	std::string graphics_latest_reply = this->_pGraphicsPipe->getLatestReply();

	if (graphics_latest_reply == "quit" || this->_gameEnd)
	{
		this->_gameEnd = true;
		return false;
	}

	// playing a move in the board class (which is responsible for the actual game)
	MoveCode moveResult = (*this->_pGameBoard).move(Position(graphics_latest_reply[SRC_COL_IDX], graphics_latest_reply[SRC_ROW_IDX]), Position(graphics_latest_reply[DST_COL_IDX], graphics_latest_reply[DST_ROW_IDX]));  // NOTE: if it's quit an exception will be thrown from position
	// sending the resultant move code and accepting a new reply
	this->_pGraphicsPipe->sendMoveCode(moveResult);
	this->_pGraphicsPipe->acceptGraphicsReply();
	return true;
}