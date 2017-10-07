#pragma once

using namespace std;

class Circle : public Shape {
	float radius;
public :
	Circle(float x, float y, float r);
	void Draw();
};

Circle::Circle(float x, float y, float r):Shape(x, y){
	radius = r;
}

void Circle::Draw() {
	cout << "[Circle] position = (" << this->x << ", " << this->y << ", radius = " << radius << ")" << endl;
}