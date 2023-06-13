#include "Player.h"
#include "Rectangle.h"
#include "Sphere.h"
#include "../GameData.h"
#include "../GameManager.h"

Player::Player(float x, float y, Scene* scene)
{
	m_Sphere = Sphere(70);
	m_Rigidbody = Rigidbody(false, true, 5);
	m_Texture.loadFromFile("./Textures/Charlie.png", sf::IntRect(0, 0, 100, 100));
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(0, 0);
	m_Scene = scene;

	ChangePosistion(rmath::Vector2(x, y));
}

void Player::Start()
{
}

void Player::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_Rigidbody.SetForce(Vector2(-30, 0));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_Rigidbody.SetForce(Vector2(30, 0));
	}

	m_Rigidbody.Update(this, dt);
}

void Player::Collision(GameObject* other)
{
	GameManager::GetInstance()->ChangeScene(GameManager::GetInstance()->m_gameOverScene);
}
