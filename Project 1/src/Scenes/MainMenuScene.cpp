#include "MainMenuScene.h"
#include <iostream>
#include "../GameManager.h"

MainMenuScene::MainMenuScene()
{
    AddButton(sf::Vector2f(500.f, 200.f), sf::Vector2f(200.f, 50.f), sf::Color::Green, []() {
        GameManager::GetInstance()->ChangeScene(GameManager::GetInstance()->m_gameScene);
    });

    AddButton(sf::Vector2f(500.f, 300.f), sf::Vector2f(200.f, 50.f), sf::Color::Blue, []() {
        std::exit(0);
    });


    m_titleFont.loadFromFile("./RobotoBold.ttf");
    m_titleText.setFont(m_titleFont);
    m_titleText.setString("Hello world");
    m_titleText.setCharacterSize(240);
    m_titleText.setFillColor(sf::Color::Red);
}

void MainMenuScene::Update(float dt)
{
}

void MainMenuScene::Draw(sf::RenderWindow& window)
{
    for (Button& button : m_buttons) {
        button.render(window);
    }

    window.draw(m_titleText);
}

void MainMenuScene::AddButton(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& fillColor, std::function<void()> onClick)
{
    m_buttons.emplace_back(position, size, fillColor, std::move(onClick));
}

std::vector<Button> MainMenuScene::GetButtons()
{
    return m_buttons;
}
