#include "GameScene.h"
#include <iostream>


GameScene::GameScene() : 
	player(new Player(500.f, 600.f, this)), 
	enemy(new Enemy(300.f, 0.f, this)), 
	enemySpawner(new EnemySpawner(400.f, 0.f, this))
{
	gameObjects.push_back(player);
	gameObjects.push_back(enemy);
	gameObjects.push_back(enemySpawner);
}

void GameScene::Update(float dt)
{
	Scene::Update(dt);

	for (GameObject* gameObject : gameObjects) 
	{
		gameObject->Update(dt);
	}
}

void GameScene::Draw(sf::RenderWindow& window)
{
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Draw(window);
	}
}
