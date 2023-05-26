#pragma once
#include <list>
#include "GameObject.h"

static class GameManager
{
private:
	std::vector <GameObject> gameObjects;

public:
	void StartAllGameObjects();
	void UpdateAllGameObjects();
	void AddNewGameObject(GameObject gameObject);
};

