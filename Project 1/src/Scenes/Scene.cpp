#include "Scene.h"
#include <iostream>

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::OnSceneLoad()
{
}

void Scene::Update(float dt)
{
	for (GameObject* gameObject : QueuedToBeDestroyedObjects) 
	{
		gameObjects.remove(gameObject);
		delete gameObject;
	}
	QueuedToBeDestroyedObjects.clear();
}

void Scene::DetectCollision()
{
	//Detect collision with circle colliders

	for (GameObject* gameObjectA : gameObjects) 
	{
		for (GameObject* gameObjectB : gameObjects) 
		{
			//If its the same object continue
			if (gameObjectA == gameObjectB) { continue; }

			Vector2 vectorDelta = gameObjectB->GetPosistion() - gameObjectA->GetPosistion();
			float vectorDeltaMagnitude = sqrt(pow(vectorDelta.x, 2) + pow(vectorDelta.y, 2));
			float spheresDistance = vectorDeltaMagnitude - gameObjectA->GetSphere().GetRadius(); - gameObjectB->GetSphere().GetRadius();

			if (spheresDistance < 0) { 
				gameObjectA->Collision(gameObjectB);
			}
		}
	}
}

void Scene::DestroyObject(GameObject* gameObject)
{
	//Queue Objects so GameObject Lists dont break when deleting
	QueuedToBeDestroyedObjects.push_back(gameObject);
}

void Scene::Draw(sf::RenderWindow& window) 
{
}
