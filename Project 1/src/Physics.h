#pragma once
#include "Vector2.h"
using namespace rmath;

class Physics
{
public:
	Vector2 posistionCurrent;
	Vector2 positionOld;
	Vector2 acceleration;
	float mass;

	void UpdatePosition(float dt) {
		const Vector2 velocity = posistionCurrent - positionOld;

		//save current position
		positionOld = posistionCurrent;

		//Perform verlet
	}
};

