#include "EnemySpawner.h"
#include "../Scenes/Scene.h"

EnemySpawner::EnemySpawner(float x, float y, Scene* scene) 
{
	m_Sphere = Sphere(70);
	m_Texture.loadFromFile("./Textures/Charlie.png", sf::IntRect(0, 0, 100, 100));
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(0, 0);
	m_Scene = scene;

	ChangePosistion(rmath::Vector2(x, y));
}

void EnemySpawner::Start()
{
	
}

void EnemySpawner::Update(float dt)
{
	spawnDelay -= dt;

	if (spawnDelay <= 0) 
	{
		Enemy* enemy = new Enemy(m_Position.x, m_Position.y, m_Scene);
		m_Scene->gameObjects.push_back(enemy);

		spawnDelay = spawnDelayAmount;
	}
}
