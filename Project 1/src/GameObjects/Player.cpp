#include "Player.h"
#include "Rectangle.h"
#include "Sphere.h"
#include "../GameData.h"
#include "../GameManager.h"

Player::Player(float x, float y, Scene* scene)
{
	m_Sphere = Sphere(70);
	m_Texture.loadFromFile("./Textures/Charlie.png", sf::IntRect(0, 0, 100, 100));
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(0, 0);
	m_Scene = scene;

	ChangePosistion(rmath::Vector2(x, y));
	speed = 200;
}

void Player::Start()
{
}

void Player::Update(float dt)
{
	if (m_Position.x < 0) 
	{ 
		m_Position.x = 0; 
		if(acceleration < 0){ acceleration = 0.f; }
	}

	else if (m_Position.x > SCREEN_WIDTH) 
	{ 
		m_Position.x = SCREEN_WIDTH; 
		if (acceleration > 0) { acceleration = 0.f; }
	}

	force = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		force = -30;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		force = 30;
	}

	
	if (acceleration > 0) 
	{ 
		friction = GRAVITY_CONSTANT * FRICTION_COEFFICIENT;
	};
	if (acceleration < 0) 
	{
		friction = -(GRAVITY_CONSTANT * FRICTION_COEFFICIENT);
	}

	deltaForce = force - friction;

	acceleration += deltaForce / mass;

	ChangePosistion(Vector2(GetPosistion().x + (acceleration ) * dt, GetPosistion().y));


}

void Player::Collision(GameObject* other)
{
	GameManager::GetInstance()->ChangeScene(GameManager::GetInstance()->m_gameOverScene);
}
