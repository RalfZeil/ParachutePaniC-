#include "Player.h"
#include "Rectangle.h"

Player::Player(float x, float y)
{
	m_Shape = Rectangle(100, 100);
	m_Texture.loadFromFile("./Textures/Charlie.png", sf::IntRect(0, 0, 100, 100));
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(0, 0);

	ChangePosistion(rmath::Vector2(x, y));
	speed = 1;
}

void Player::Start()
{
}

void Player::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		ChangePosistion(Vector2(GetPosistion().x - speed, GetPosistion().y));
		m_Sprite.setRotation(45);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		ChangePosistion(Vector2(GetPosistion().x + speed, GetPosistion().y));
		m_Sprite.setRotation(315);
	}
}
