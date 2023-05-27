#include "Button.h"

Button::Button(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& fillColor, std::function<void()> onClick)
	: m_shape(size), m_onClick(std::move(onClick)) {
	m_shape.setPosition(position);
	m_shape.setFillColor(fillColor);
}

void Button::render(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

bool Button::isMouseOver(const sf::Vector2f& mousePosition) const
{
	return m_shape.getGlobalBounds().contains(mousePosition);
}

void Button::handleClick()
{
	if (m_onClick)
		m_onClick();
}
