// INCLUDES
#include "Solider.h"

// FUNCTIONS & METHODS

Solider::~Solider()
{

}
Solider::Solider(const Position& position, const Color& color, const Board* pGameBoard) :
	_position(position), _color(color), _pBoard(pGameBoard)
{
}

Color Solider::color(void) const
{
	return this->_color;
}

Position Solider::position(void) const
{
	return this->_position;
}

const Board* Solider::pBoard(void) const
{
	return this->_pBoard;
}
void Solider::setColor(Color newColor)
{
	this->_color = newColor;
}

void Solider::setPosition(Position newPosition)
{
	this->_position = newPosition;
}


