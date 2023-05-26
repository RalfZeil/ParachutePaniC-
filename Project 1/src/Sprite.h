#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h"

using namespace rmath;

class Sprite
{
private:
	sf::Texture m_Texture;
	Vector2 m_Offset;

public:
	void Draw();
	void SetTexture(sf::Texture newTexture);
};

