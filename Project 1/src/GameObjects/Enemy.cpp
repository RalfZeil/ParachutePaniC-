#include "Enemy.h"
#include "Sphere.h"

Enemy::Enemy(float x, float y)
{
	m_Shape = Sphere(100);
	m_Texture.loadFromFile("./Textures/Charlie.png", sf::IntRect(0, 0, 100, 100));
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(0, 0);

	ChangePosistion(rmath::Vector2(x, y));
}

void Enemy::Start()
{
}

void Enemy::Update(float dt)
{
}
