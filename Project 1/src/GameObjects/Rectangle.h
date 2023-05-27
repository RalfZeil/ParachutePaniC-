#pragma once
#include "IShape.h"
class Rectangle : public IShape
{
private:
	float m_Width;
	float m_Heigth;

public:
	Rectangle(float width, float height);
	virtual float GetArea() override;
	virtual bool Collides(IShape other) override;
};

