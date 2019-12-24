#include "Game.h"

Game::Game()
{
	this->_gameBoard = Board(INITIAL_BOARD);
	char initMessageToSend[MSG_SIZE] = INITIAL_BOARD;
	this->_gp = GraphicsPipe(initMessageToSend);
}
void Game::update()
{
	std::string graphics_latest_reply = this->_gp.getLatestReply();
	MoveCode moveResult = this->_gameBoard.move(Position(graphics_latest_reply[SRC_COL_IDX], graphics_latest_reply[SRC_ROW_IDX]), Position(graphics_latest_reply[DST_COL_IDX], graphics_latest_reply[DST_ROW_IDX]));  // NOTE: if it's quit an exception will be thrown from position
	this->_gp.sendMoveCode(moveResult);
	this->_gp.getLatestReply();
}