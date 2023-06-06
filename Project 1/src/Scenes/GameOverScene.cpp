#include "GameOverScene.h"
#include <iostream>
#include "../GameManager.h"

GameOverScene::GameOverScene()
{
    AddButton(sf::Vector2f(500.f, 200.f), sf::Vector2f(200.f, 50.f), sf::Color::Green, []() {
        GameManager::GetInstance()->ChangeScene(GameManager::GetInstance()->m_gameScene);
        });

    AddButton(sf::Vector2f(500.f, 300.f), sf::Vector2f(200.f, 50.f), sf::Color::Blue, []() {
        std::exit(0);
        });
}

void GameOverScene::Update(float dt)
{
}

void GameOverScene::Draw(sf::RenderWindow & window)
{
    for (Button& button : m_buttons) {
        button.render(window);
    }
}

void GameOverScene::AddButton(const sf::Vector2f & position, const sf::Vector2f & size, const sf::Color & fillColor, std::function<void()> onClick)
{
    m_buttons.emplace_back(position, size, fillColor, std::move(onClick));
}

std::vector<Button> GameOverScene::GetButtons()
{
    return m_buttons;
}
