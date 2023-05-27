#include "GameScene.h"
#include <iostream>

GameScene::GameScene()
{
	rectangle = sf::RectangleShape(sf::Vector2f(120, 50));
	rectangle.setScale(sf::Vector2f(2, 2));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(sf::Vector2f(200, 200));
}

void GameScene::Update()
{
}

void GameScene::Draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
}
