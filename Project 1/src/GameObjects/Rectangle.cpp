#include "Rectangle.h"

Rectangle::Rectangle(float width, float height) 
	: m_Width(width), m_Height(height) {}

float Rectangle::GetWidth()
{
	return m_Width;
}

float Rectangle::GetHeight()
{
	return m_Height;
}

float Rectangle::GetArea()
{
	return m_Width * m_Height;
}

bool Rectangle::Collides(IShape other)
{
	return false;
}
