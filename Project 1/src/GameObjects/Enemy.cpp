#include "Enemy.h"
#include "Sphere.h"
#include "../GameData.h"

Enemy::Enemy(float x, float y)
{
	m_Sphere = Sphere(70);
	m_Texture.loadFromFile("./Textures/Charlie.png", sf::IntRect(0, 0, 100, 100));
	//m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(0, 0);

	ChangePosistion(rmath::Vector2(x, y));
}

void Enemy::Start()
{
}

void Enemy::Update(float dt)
{
	if (m_Position.x < 0)
	{
		m_Position.x = 0;
		if (acceleration < 0) { acceleration = 0.f; }
	}

	else if (m_Position.x > SCREEN_WIDTH)
	{
		m_Position.x = SCREEN_WIDTH;
		if (acceleration > 0) { acceleration = 0.f; }
	}

	force = 20;

	deltaForce = force - friction;

	acceleration += deltaForce / mass;

	ChangePosistion(Vector2(GetPosistion().x, GetPosistion().y + (acceleration)*dt));
}
