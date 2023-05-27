#include "Rectangle.h"

Rectangle::Rectangle(float width, float height) 
	: m_Width(width), m_Heigth(height) {}

float Rectangle::GetArea()
{
	return m_Width * m_Heigth;
}

bool Rectangle::Collides(IShape other)
{
	return false;
}
