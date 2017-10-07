#pragma once

using namespace std;

class Shape {
protected:
	float x, y;
public:
	Shape(float ix, float iy);
	virtual void Draw();
};

Shape::Shape(float ix, float iy) {
	x = ix;
	y = iy;
}

void Shape::Draw() {
	cout << "[SHAPE] position (" << x << ", " << y << ")" << endl;
}