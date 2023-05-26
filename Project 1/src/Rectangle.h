#pragma once
#include "IShape.h"
class Rectangle : public IShape
{
private:
	float m_Width;
	float m_Heigth;

public:
	virtual float GetArea();
	virtual bool Collides(IShape other);
};

