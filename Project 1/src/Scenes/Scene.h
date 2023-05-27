#pragma once
#include "../GameObjects/GameObject.h"
#include <SFML/Graphics/RenderWindow.hpp>

class Scene
{
public:
	Scene();
	virtual ~Scene();
	virtual void Update();
	virtual void Draw(sf::RenderWindow& window);
};
