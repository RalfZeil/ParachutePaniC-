#include "Vector2.h"
#include <cmath>


namespace rmath {

	Vector2::Vector2(float x, float y)
		: x(x), y(y)
	{}

	Vector2 Vector2::operator/(const float divisor)
	{
		return Vector2(x / divisor, y / divisor);
	}

	Vector2 Vector2::operator*(const float multiplier)
	{
		return Vector2(x * multiplier, y + multiplier);
	}

	Vector2 Vector2::operator+(const Vector2 additor)
	{
		return Vector2(x + additor.x, y + additor.y);
	}

	Vector2 Vector2::operator-(const Vector2 substractor)
	{
		return Vector2(x - substractor.x, y - substractor.y);
	}

	Vector2& Vector2::operator+=(const Vector2 additor)
	{
		x += additor.x;
		y += additor.y;
		return *this;
	}

	float Vector2::Magnitude(Vector2 vector2)
	{
		return sqrt(pow(vector2.x, 2) + (pow(vector2.y, 2)));
	}

	float Vector2::SquareMagnitude(Vector2 vector2)
	{
		return pow(vector2.x, 2) + pow(vector2.y, 2);
	}

	Vector2 Vector2::Normalize(Vector2 vector2)
	{
		return vector2 / Magnitude(vector2);
	}

	float Vector2::DotProduct(Vector2 v1, Vector2 v2)
	{
		return (v1.x * v2.x) + (v1.y * v2.y);
	}
}
