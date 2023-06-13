#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameObject::GameObject()
{
}

GameObject::GameObject(Vector2 pos, Sphere sphere, Rigidbody rigidbody,sf::Sprite sprite, Scene* scene)
	: m_Position(pos), m_Sphere(sphere), m_Rigidbody(rigidbody), m_Sprite(sprite), m_Scene(scene)
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

Sphere GameObject::GetSphere()
{
	return m_Sphere;
}

void GameObject::Collision(GameObject* other)
{
}

void GameObject::Start()
{
}

void GameObject::Update(float dt)
{
}

void GameObject::ResetRigidbody() 
{
	m_Rigidbody.Reset();
}

void GameObject::Draw(sf::RenderWindow& window)
{
	window.draw(m_Sprite);	
}
