#pragma once
#include "../Vector2.h"
#include "IShape.h"
#include "Sphere.h"
#include "sfml/Graphics.hpp"

using namespace rmath;

class GameObject
{
protected:
	Vector2 m_Position;
	Sphere m_Sphere;
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;

public:
	GameObject();
	GameObject(Vector2 pos, Sphere sphere, sf::Sprite sprite);
	void ChangePosistion(Vector2 newPosition);
	Vector2 GetPosistion();
	Sphere GetSphere();
	virtual void Start();
	virtual void Update(float dt);
	void Draw(sf::RenderWindow& window);

};

