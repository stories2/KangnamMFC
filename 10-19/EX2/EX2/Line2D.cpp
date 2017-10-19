#include "stdafx.h"
#include "Line2D.h"


Line2D::Line2D()
{
}


Line2D::~Line2D()
{
}

void Line2D::Draw(CDC &dc) {
	dc.MoveTo(start.x, start.y);
	dc.LineTo(end.x, end.y);

	printf("line2d draw\n");
}
