#include "GameScene.h"
#include <iostream>


GameScene::GameScene() : player(new Player(500.f, 600.f))
{}

void GameScene::Update()
{
	player->Update();
}

void GameScene::Draw(sf::RenderWindow& window)
{
	player->Draw(window);
}
