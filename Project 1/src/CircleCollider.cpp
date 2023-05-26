#include "CircleCollider.h"

CircleCollider::CircleCollider()
{
	radius = 0;
}

CircleCollider::CircleCollider(float radius) :
	radius(radius) 
{}

void CircleCollider::ChangeRadius(float newSize)
{
	radius = newSize;
}
