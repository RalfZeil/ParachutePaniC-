#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(float x, float y, std::list<GameObject*> &gameSceneGameObjectsList) 
	: gameSceneGameObjects(gameSceneGameObjectsList)
{
	m_Sphere = Sphere(70);
	m_Texture.loadFromFile("./Textures/Charlie.png", sf::IntRect(0, 0, 100, 100));
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(0, 0);

	ChangePosistion(rmath::Vector2(x, y));
}

void EnemySpawner::Start()
{
	
}

void EnemySpawner::Update(float dt)
{
	//Enemy* enemy = new Enemy(m_Position.x, m_Position.y);
	//gameSceneGameObjects.push_back(enemy);
}
