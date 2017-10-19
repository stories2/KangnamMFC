#pragma once

#include "Shape2D.h"

class Line2D : public Shape2D
{
public:
	CPoint start, end;
public:
	Line2D();
	~Line2D();
public:
	void Draw(CDC &dc);
};

