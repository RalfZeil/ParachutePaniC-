#include "GameScene.h"
#include <iostream>


GameScene::GameScene() : player(new Player(500.f, 600.f)), enemy(new Enemy(300.f, 600.f))
{
	gameObjects.push_back(player);
	gameObjects.push_back(enemy);
}

void GameScene::Update(float dt)
{
	player->Update(dt);
	enemy->Update(dt);
}

void GameScene::Draw(sf::RenderWindow& window)
{
	player->Draw(window);
	enemy->Draw(window);
}
