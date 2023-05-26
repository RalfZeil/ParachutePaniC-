#pragma once
class IShape
{
public:
	virtual float GetArea();
	virtual bool Collides(IShape other);
};

