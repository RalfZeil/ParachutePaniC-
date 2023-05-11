#pragma once
#include <SFML/Graphics/Texture.hpp>
#include "CircleCollider.h"
#include "Physics.h"


class GameObject
{
private:
	sf::Texture objectTexture;
	CircleCollider collider;
	Physics physics;

public:
	GameObject(std::string texLocation, float size);
	virtual void Start();
	virtual void Update();
};

