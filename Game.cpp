#include "Game.h"

Game::Game()
{
	this->_pGameBoard = new Board(INITIAL_BOARD);
	char initMessageToSend[MSG_SIZE] = INITIAL_BOARD;
	this->_pGraphicsPipe = new GraphicsPipe(initMessageToSend);
}
void Game::update()
{
	std::string graphics_latest_reply = this->_pGraphicsPipe->getLatestReply();
	MoveCode moveResult = (*this->_pGameBoard).move(Position(graphics_latest_reply[SRC_COL_IDX], graphics_latest_reply[SRC_ROW_IDX]), Position(graphics_latest_reply[DST_COL_IDX], graphics_latest_reply[DST_ROW_IDX]));  // NOTE: if it's quit an exception will be thrown from position
	this->_pGraphicsPipe->sendMoveCode(moveResult);
	this->_pGraphicsPipe->acceptGraphicsReply();
}