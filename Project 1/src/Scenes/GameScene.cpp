#include "GameScene.h"

GameScene::GameScene()
{
	rect.setScale(sf::Vector2f(300, 300));
}

void GameScene::Update()
{
}

void GameScene::Draw(sf::RenderWindow& window)
{
	window.draw(rect);
}
