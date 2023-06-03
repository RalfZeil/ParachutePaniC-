#pragma once
#include "IShape.h"
class Sphere : public IShape
{
private:
	float m_Radius;

public:
	Sphere(float radius);
	virtual float GetRadius() override;
	virtual float GetArea() override;
	virtual bool Collides(IShape other) override;
};

