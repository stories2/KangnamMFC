#pragma once

using namespace std;

class Rect : public Shape {
	float width, height;
public:
	Rect(double x, double y, double w, double h);
	void Draw();
};

Rect::Rect(double x, double y, double w, double h) :Shape(x, y) {
	width = w;
	height = h;
}

void Rect::Draw() {
	cout << "[RECTANGLE] position = (" << x << ", " << y << ")" << ", size = (" << width << ", " << height << ")" << endl;
}