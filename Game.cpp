#include "Game.h"

Game::Game()
{
	this->_pGameBoard = new Board(INITIAL_BOARD);
	char initMessageToSend[MSG_SIZE] = INITIAL_BOARD;
	this->_pGraphicsPipe = new GraphicsPipe(initMessageToSend);
	PlaySound("gameSong.wav", NULL, SND_LOOP | SND_ASYNC);

}
Game::~Game()
{
	delete this->_pGameBoard;
	delete this->_pGraphicsPipe;
}
bool Game::update()
{

	std::string graphics_latest_reply = this->_pGraphicsPipe->getLatestReply();

	if (graphics_latest_reply == "quit" || this->_gameEnd)
	{
		this->_gameEnd = true;
		return false;
	}

	MoveCode moveResult = (*this->_pGameBoard).move(Position(graphics_latest_reply[SRC_COL_IDX], graphics_latest_reply[SRC_ROW_IDX]), Position(graphics_latest_reply[DST_COL_IDX], graphics_latest_reply[DST_ROW_IDX]));  // NOTE: if it's quit an exception will be thrown from position
	this->_pGraphicsPipe->sendMoveCode(moveResult);
	this->_pGraphicsPipe->acceptGraphicsReply();
	return true;
}