#include "GameObject.h"
#include <SFML/Graphics.hpp>

GameObject::GameObject()
{
}

GameObject::GameObject(Vector2 pos, IShape shape, sf::Sprite sprite) 
	: m_Position(pos), m_Shape(shape), m_Sprite(sprite) 
{
	ChangePosistion(pos);
}

void GameObject::ChangePosistion(Vector2 newPosition)
{
	GameObject::m_Position = newPosition;
	m_Sprite.setPosition(m_Position.x, m_Position.y);
}

Vector2 GameObject::GetPosistion()
{
	return m_Position;
}

void GameObject::Start()
{
}

void GameObject::Update()
{
}

void GameObject::Draw(sf::RenderWindow& window)
{
	window.draw(m_Sprite);	
}
