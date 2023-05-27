#pragma once
#include "Vector2.h"
#include "IShape.h"
#include "Sprite.h"

using namespace rmath;

class GameObject
{
private:
	Vector2 m_Position;
	IShape shape;
	Sprite sprite;

public:
	GameObject();
	GameObject(Vector2 pos, IShape shape, Sprite sprite);
	void ChangePosistion(Vector2 newPosition);
	void Start();
	void Update();
};

