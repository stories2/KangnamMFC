#pragma once

#include "DefineManager.h"

class Position
{
	int x, y;
public:
	Position();
	void SetPosition(int x, int y);
	void SetPosition(Position position);
	Position GetPosition();
	~Position();
};

