#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class TwoD_Shape // Base Class
{
public:
	double width;
	double height;

	void showDim() {
		std::cout << "Width and height are " << width << " and " << height << std::endl;
	}
};

class Triangle : public TwoD_Shape // Derived Class
{
public:
	char style[20];
	double area() {
		return width * height / 2;
	}

	void showStyle() {
		std::cout << "Triangle is " << style << std::endl;
	}
};

int main() {
	TwoD_Shape shape;
	shape.width = 1;
	shape.height = 1;
	shape.showDim();

	Triangle my_Triangle;
	strcpy(my_Triangle.style, "my triangle");

	my_Triangle.showStyle();
	return 0;
}

