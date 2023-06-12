#include "GameOverScene.h"
#include <iostream>
#include "../GameManager.h"

GameOverScene::GameOverScene()
{
    AddButton(sf::Vector2f(500.f, 500.f), sf::Vector2f(200.f, 50.f), sf::Color::Green, []() {
        GameManager::GetInstance()->ChangeScene(GameManager::GetInstance()->m_gameScene);
        });

    AddButton(sf::Vector2f(500.f, 600.f), sf::Vector2f(200.f, 50.f), sf::Color::Red, []() {
        std::exit(0);
        });

    m_titleFont.loadFromFile("./Fonts/RobotoBold.ttf");

    SetTitleText();
}

void GameOverScene::Update(float dt)
{
    m_highScoreText.setString("Highscore: " + std::to_string(GameManager::GetInstance()->GetHighScore()));
}

void GameOverScene::Draw(sf::RenderWindow & window)
{
    for (Button& button : m_buttons) {
        button.render(window);
    }

    window.draw(m_titleText);
    window.draw(m_highScoreText);
}

void GameOverScene::AddButton(const sf::Vector2f & position, const sf::Vector2f & size, const sf::Color & fillColor, std::function<void()> onClick)
{
    m_buttons.emplace_back(position, size, fillColor, std::move(onClick));
}

std::vector<Button> GameOverScene::GetButtons()
{
    return m_buttons;
}

void GameOverScene::SetTitleText()
{
    //Title Text
    m_titleText.setFont(m_titleFont);
    m_titleText.setString("Game Over");
    m_titleText.setCharacterSize(100);
    m_titleText.setFillColor(sf::Color::White);
    m_titleText.setOrigin(sf::Vector2f(-350, -100));

    //HighScore Text
    m_highScoreText.setFont(m_titleFont);
    m_highScoreText.setString("Highscore: 0");
    m_highScoreText.setCharacterSize(60);
    m_highScoreText.setFillColor(sf::Color::White);
    m_highScoreText.setOrigin(sf::Vector2f(-425, -250));
}
