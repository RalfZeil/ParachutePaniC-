#pragma once
#include "Vector2.h"

class CircleCollider
{
private:
	float radius;

public:
	CircleCollider();
	CircleCollider(float radius);

	void ChangeRadius(float newSize);
};

