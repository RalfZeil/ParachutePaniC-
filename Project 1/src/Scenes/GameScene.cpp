#include "GameScene.h"
#include <iostream>
#include "../GameManager.h"
#include "../GameData.h"

using namespace std;


GameScene::GameScene() : 
	player(new Player(500.f, 600.f, this)), 
	enemySpawner(new EnemySpawner(SCREEN_WIDTH/2, -100.f, this))
{
	gameObjects.push_back(player);
	gameObjects.push_back(enemySpawner);


	m_font.loadFromFile("./Fonts/RobotoBlack.ttf");

	m_scoreCounter.setFont(m_font);
	m_scoreCounter.setString("Score: " + std::to_string(m_score));
	m_scoreCounter.setCharacterSize(50);
	m_scoreCounter.setFillColor(sf::Color::White);
}

void GameScene::OnSceneLoad()
{
	//Reset the scene each time it loads
	for(GameObject* object : gameObjects) 
	{
		Enemy* enemy = dynamic_cast<Enemy*>(object);
		if (enemy) {
			DestroyObject(object);
		}
	}

	player->ChangePosistion(rmath::Vector2(500.f, 600.f));
	player->ResetRigidbody();
	enemySpawner->ChangePosistion(rmath::Vector2(SCREEN_WIDTH / 2, -100.f));

	m_score = 0;

	m_scoreCounter.setString("Score: " + std::to_string(m_score));
}

void GameScene::Update(float dt)
{
	Scene::Update(dt);

	for (GameObject* gameObject : gameObjects) 
	{
		gameObject->Update(dt);
	}


	//Give player points per second alive
	m_scoreTimer -= dt;

	if (m_scoreTimer <= 0) 
	{
		m_scoreTimer = m_timePerPoint;
		m_score += 1;

		GameManager::GetInstance()->SubmitScore(m_score);

		m_scoreCounter.setString("Score: " + std::to_string(m_score));
	}
}

void GameScene::Draw(sf::RenderWindow& window)
{
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->Draw(window);
	}

	window.draw(m_scoreCounter);
}


