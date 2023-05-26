#pragma once
#include "Shape.h"
#include "Vector2.h"

using namespace rmath;

class Rectangle : public Shape
{
private:
	int width, height;
	Vector2 position;
public:
	Rectangle(int w, int h, Vector2 pos);
	float Area();
	void Draw();
};

