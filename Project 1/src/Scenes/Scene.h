#pragma once
#include "../GameObjects/GameObject.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include <functional>

class Scene
{
protected:
	std::list<const GameObject&> gameObjects;

public:
	Scene();
	virtual ~Scene();
	virtual void Update(float dt);
	void DetectCollision();
	virtual void Draw(sf::RenderWindow& window);
};

