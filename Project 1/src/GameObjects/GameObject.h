#pragma once
#include "../Vector2.h"
#include "IShape.h"
#include "sfml/Graphics.hpp"

using namespace rmath;

class GameObject
{
protected:
	Vector2 m_Position;
	IShape m_Shape;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;

public:
	GameObject();
	GameObject(Vector2 pos, IShape shape, sf::Sprite sprite);
	void ChangePosistion(Vector2 newPosition);
	Vector2 GetPosistion();
	virtual void Start();
	virtual void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

