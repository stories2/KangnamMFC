#include "homework1.h"

int main()
{
	Shape *shapes[5] = { NULL }; 
	shapes[0] = new Circle(100, 100, 50); 
	shapes[1] = new Rect(300, 300, 100, 100); 
	shapes[2] = new Rect(200, 100, 50, 150); 
	shapes[3] = new Circle(100, 300, 150); 
	shapes[4] = new Rect(200, 200, 200, 200);

	for (int i = 0; i < 5; i++) { 
		shapes[i]->Draw(); 
	}
	for (int i = 0; i < 5; i++) { 
		delete shapes[i]; 
		shapes[i] = NULL; 
	}

    return 0;
}

