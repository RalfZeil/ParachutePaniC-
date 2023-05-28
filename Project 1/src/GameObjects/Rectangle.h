#pragma once
#include "IShape.h"
class Rectangle : public IShape
{
private:
	float m_Width;
	float m_Height;

public:
	Rectangle(float width, float height);
	float GetWidth();
	float GetHeight();

	virtual float GetArea() override;
	virtual bool Collides(IShape other) override;
};

