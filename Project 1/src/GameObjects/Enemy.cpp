#include "Enemy.h"
#include "Sphere.h"
#include "../GameData.h"
#include "../Scenes/Scene.h"

Enemy::Enemy(float x, float y, Scene* scene)
{
	m_Sphere = Sphere(70);
	m_Rigidbody = Rigidbody(true, true, 30);
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
	m_stateTimer -= dt;

	//Switch state every 0-1 seconds
	if (m_stateTimer < 0) 
	{
		m_stateTimer = (float) rand()/RAND_MAX;
		m_state = std::rand() % 3;
	}

	//State 0 is dont move, 1 move left, 2 move right
	switch (m_state) 
	{
		case 0:
			m_Rigidbody.SetForce(Vector2(0, 15));
			break;
		case 1:
			m_Rigidbody.SetForce(Vector2(-15, 10));
			break;
		case 2:
			m_Rigidbody.SetForce(Vector2(15, 10));
			break;
	}

	m_Rigidbody.Update(this, dt);
}
