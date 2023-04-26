#pragma once
class Vector2
{
	float x;
	float y;

public:
	Vector2(float x = 0, float y = 0);

	Vector2 operator / (float divisor);
	Vector2 operator * (float multiplier);
	Vector2 operator + (Vector2 additor);
	Vector2 operator - (Vector2 substractor);


	static float Magnitude(Vector2 vector2);
	static float SquareMagnitude(Vector2 vector2);
	static Vector2 Normalize(Vector2 vector2);

	static float DotProduct(Vector2 v1, Vector2 v2);
	//static Vector3 CrossProduct(Vector2, Vector2);
};

