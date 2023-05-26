#include "Rectangle.h"
#include <SFML/Graphics.hpp>

Rectangle::Rectangle(int w, int h, Vector2 pos)
{
	width = w;
	height = h;
	position = pos;
}

float Rectangle::Area()
{
	return width * height;
}

void Rectangle::Draw()
{
}
