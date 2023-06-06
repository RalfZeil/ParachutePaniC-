#include "Enemy.h"
#include "Sphere.h"
#include "../GameData.h"
#include "../Scenes/Scene.h"

Enemy::Enemy(float x, float y, Scene* scene)
{
	m_Sphere = Sphere(70);
	m_Texture.loadFromFile("./Textures/Charlie.png", sf::IntRect(0, 0, 100, 100));
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(0, 0);
	m_Scene = scene;

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

	if (m_Position.y > SCREEN_HEIGHT) { m_Scene->DestroyObject(this); }

	force = 20;

	deltaForce = force - friction;
	
	acceleration += deltaForce / mass;

	ChangePosistion(Vector2(GetPosistion().x, GetPosistion().y + (acceleration)*dt));
}
