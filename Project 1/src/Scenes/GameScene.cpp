#include "GameScene.h"
#include <iostream>


GameScene::GameScene()
{
	Player* player = new Player(500.f, 500.f);
}

void GameScene::Update()
{
	
}

void GameScene::Draw(sf::RenderWindow& window)
{
	player->Draw(window);
}
