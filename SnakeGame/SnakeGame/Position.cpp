#include "stdafx.h"
#include "Position.h"


Position::Position()
{
	this->x = ZERO;
	this->y = ZERO;
}

void Position::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Position::SetPosition(Position position)
{
	this->x = position.x;
	this->y = position.y;
}

Position Position::GetPosition()
{
	return *this;
}


Position::~Position()
{
}
