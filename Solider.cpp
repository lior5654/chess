// INCLUDES
#include "Solider.h"

// FUNCTIONS & METHODS
Solider::Solider(const Position& position, const Color& color) :
	_position(position), _color(color)
{
}

Color Solider::color() const
{
	return this->_color;
}

Position Solider::position() const
{
	return this->_position;
}

void Solider::setColor(Color newColor)
{
	this->_color = newColor;
}

void Solider::setPosition(Position newPosition)
{
	this->_position = newPosition;
}