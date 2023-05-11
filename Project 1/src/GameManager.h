#pragma once
#include <list>
#include "GameObject.h"

static class GameManager
{
private:
	static std::vector <GameObject> gameObjects;

public:
	static void StartAllGameObjects();
	static void UpdateAllGameObjects();
	static void AddNewGameObject(GameObject gameObject);
};

