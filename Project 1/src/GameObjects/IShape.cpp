#include "IShape.h"

float IShape::GetArea()
{
	return 0.0f;
}

bool IShape::Collides(IShape other)
{
	return false;
}

float IShape::GetRadius()
{
	return 0.f;
}
