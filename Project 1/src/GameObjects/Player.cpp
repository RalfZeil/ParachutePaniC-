#include "Player.h"
#include "Rectangle.h"

Player::Player(float x, float y)
{
	sf::Texture texture;
	texture.loadFromFile("./Textures/Charlie.png", sf::IntRect(0, 0, 64, 64));
	m_Sprite.setTexture(texture);

	m_Shape = Rectangle(100, 100);

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
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		ChangePosistion(Vector2(GetPosistion().x + speed, GetPosistion().y));
	}
}
