#include "MainMenuScene.h"
#include <iostream>

MainMenuScene::MainMenuScene()
{
    AddButton(sf::Vector2f(500.f, 200.f), sf::Vector2f(200.f, 50.f), sf::Color::Green, []() {
        std::cout << "Hello" << std::endl;
    });

    AddButton(sf::Vector2f(500.f, 300.f), sf::Vector2f(200.f, 50.f), sf::Color::Blue, []() {
        std::cout << "Woa" << std::endl;
    });
}

void MainMenuScene::Update()
{
}

void MainMenuScene::Draw(sf::RenderWindow& window)
{
    for (Button& button : m_buttons) {
        button.render(window);
    }
}

void MainMenuScene::AddButton(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& fillColor, std::function<void()> onClick)
{
    m_buttons.emplace_back(position, size, fillColor, std::move(onClick));
}

std::vector<Button> MainMenuScene::GetButtons()
{
    return m_buttons;
}
