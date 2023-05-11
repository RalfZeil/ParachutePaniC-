#include "GameManager.h"

void GameManager::StartAllGameObjects()
{
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i].Start();
	}
}

void GameManager::UpdateAllGameObjects()
{
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i].Update();
	}
}

void GameManager::AddNewGameObject(GameObject gameObject)
{
	gameObjects.insert(gameObjects.begin(), gameObject);
}
