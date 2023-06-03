#include "Scene.h"
#include <iostream>

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Update(float dt)
{
}

void Scene::DetectCollision()
{
	for (GameObject* gameObjectA : gameObjects) 
	{
		for (GameObject* gameObjectB : gameObjects) 
		{
			if (&gameObjectA == &gameObjectB) { break; }

			Vector2 vectorDelta = gameObjectB->GetPosistion() - gameObjectA->GetPosistion();
			float vectorDeltaMagnitude = sqrt(pow(vectorDelta.x, 2) + pow(vectorDelta.y, 2));
			float spheresDistance = vectorDeltaMagnitude - gameObjectA->GetShape().GetRadius(); -gameObjectB->GetShape().GetRadius();

			if (vectorDeltaMagnitude < 0) { std::cout << "Collision" << std::endl; }

			else { 
				std::cout << gameObjectA->GetShape().GetRadius() << " " << gameObjectA->GetPosistion().x << " " << gameObjectA->GetPosistion().y << std::endl;
				std::cout << gameObjectB->GetShape().GetRadius() << " " << gameObjectB->GetPosistion().x << " " << gameObjectB->GetPosistion().y << std::endl;
			}
		}
	}
}

void Scene::Draw(sf::RenderWindow& window)
{
}
