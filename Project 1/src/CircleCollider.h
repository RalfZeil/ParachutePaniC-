#pragma once
#include "Vector2.h"

class CircleCollider
{
private:
	Vector2 relativePosition;
	float radius;

public:
	CircleCollider(Vector2 relativePosition, float radius);
};

