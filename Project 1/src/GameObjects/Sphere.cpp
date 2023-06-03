#include "Sphere.h"

Sphere::Sphere(float radius) : m_Radius(radius)
{
}

float Sphere::GetRadius()
{
	return m_Radius;
}

float Sphere::GetArea()
{
	return 0.0f;
}


bool Sphere::Collides(IShape other)
{
	return false;
}
