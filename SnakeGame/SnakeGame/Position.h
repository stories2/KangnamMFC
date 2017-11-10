#pragma once

#include "DefineManager.h"

class Position
{
	int x, y;
public:
	Position();
	void SetPosition(int x, int y);
	Position GetPosition();
	~Position();
};

