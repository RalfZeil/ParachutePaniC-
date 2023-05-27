#include "Player.h"
#include "Rectangle.h"

Player::Player(float x, float y)
{
	sf::Texture texture;
	texture.loadFromFile("/Textures/Charlie.png");
	m_Sprite.setTexture(texture);

	m_Shape = Rectangle(100, 100);

	ChangePosistion(rmath::Vector2(x, y));
	speed = 5;
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
