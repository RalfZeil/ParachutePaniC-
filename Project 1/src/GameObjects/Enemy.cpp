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
	m_Rigidbody.Update(this, dt);
}
