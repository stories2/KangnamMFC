#pragma once

using namespace std;

class Shape {
	float x, y;
public:
	Shape(float ix, float iy);
	void Draw();
};

Shape::Shape(float ix, float iy) {
	x = ix;
	y = iy;
}

void Shape::Draw() {
	cout << "[SHAPE] position (" << x << ", " << y << ")" << endl;
}