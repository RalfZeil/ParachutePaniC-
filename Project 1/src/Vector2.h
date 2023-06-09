#pragma once

namespace rmath {

	class Vector2
	{
	public:
		float x;
		float y;

		Vector2(float x = 0, float y = 0);

		Vector2 operator / (const float divisor);
		Vector2 operator * (const float multiplier);
		Vector2 operator + (const Vector2 additor);
		Vector2 operator - (const Vector2 substractor);
		Vector2& operator += (const Vector2 additor);
		bool operator != (const Vector2 other);
		bool operator == (const Vector2 other);

		static float Magnitude(Vector2 vector2);
		static float SquareMagnitude(Vector2 vector2);
		static Vector2 Normalize(Vector2 vector2);
		static float DotProduct(Vector2 v1, Vector2 v2);
	};
}

