#include "Queen.h"

Queen::Queen(const Position& position, const Color& color, const Board* pGameBoard) :
	Solider(position, color, pGameBoard)
{
	this->_rook = new Rook(position, color, pGameBoard);
	this->_bishop = new Bishop(position, color, pGameBoard);
}
bool Queen::canMove(const Position& dest)
{
	return this->_rook->canMove(dest) || this->_bishop->canMove(dest);
}
void Queen::setPosition(Position newPosition)
{
	this->_rook->setPosition(newPosition);
	this->_bishop->setPosition(newPosition);
	Solider::setPosition(newPosition);
}
Queen::~Queen()
{
	delete this->_rook;
	delete this->_bishop;
}


