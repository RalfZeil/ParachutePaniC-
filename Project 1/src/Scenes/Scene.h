#pragma once
#include "../GameObjects/GameObject.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <list>
#include <functional>

class Scene
{
private:
	std::vector<GameObject*> QueuedToBeDestroyedObjects;
public:
	std::list<GameObject*> gameObjects;
	Scene();
	virtual ~Scene();
	virtual void OnSceneLoad();
	virtual void Update(float dt);
	void DetectCollision();
	void DestroyObject(GameObject* gameObject);
	virtual void Draw(sf::RenderWindow& window);
};

