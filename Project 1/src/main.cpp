#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include <iostream>
#include "GameManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "Parachute Panic");

    /*sf::Sprite sprite;
    sf::Texture texture;

    texture.loadFromFile("Textures/Charlie.png");
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(250, 250));
    sprite.scale(sf::Vector2f(3, 3));*/

    sf::CircleShape shape(50.f);

    // set the shape color to green
    shape.setFillColor(sf::Color(100, 250, 50));

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Cyan);
        window.draw(shape);
        window.display();
    }

    return 0;
}