#pragma once
#include <SFML/Graphics.hpp>;
#include <functional>

class Button
{
public:
    Button(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& fillColor, std::function<void()> onClick);
    void render(sf::RenderWindow& window);
    bool isMouseOver(const sf::Vector2f& mousePosition) const;
    void handleClick();

private:
    sf::RectangleShape m_shape;
    std::function<void()> m_onClick;
};

