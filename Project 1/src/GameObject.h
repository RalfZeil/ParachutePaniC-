#pragma once
#include <SFML/Graphics/Texture.hpp>
#include "CircleCollider.h"
#include "Physics.h"


class GameObject
{
public:
	sf::Texture objectTexture;
	CircleCollider collider;
	Physics physics;
};

