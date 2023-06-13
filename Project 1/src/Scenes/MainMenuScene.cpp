#include "MainMenuScene.h"
#include <iostream>
#include "../GameManager.h"

MainMenuScene::MainMenuScene()
{
    //Start Button
    AddButton(sf::Vector2f(500.f, 500.f), sf::Vector2f(200.f, 50.f), sf::Color::Green, []() {
        GameManager::GetInstance()->ChangeScene(GameManager::GetInstance()->m_gameScene);
    });

    //Quit Button
    AddButton(sf::Vector2f(500.f, 600.f), sf::Vector2f(200.f, 50.f), sf::Color::Red, []() {
        std::exit(0);
    });


    m_titleFont.loadFromFile("./Fonts/RobotoBold.ttf");

    SetTitleText();
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

void MainMenuScene::SetTitleText()
{
    //TitleText
    m_titleText.setFont(m_titleFont);
    m_titleText.setString("Capybara Panic");
    m_titleText.setCharacterSize(100);
    m_titleText.setFillColor(sf::Color::White);
    m_titleText.setOrigin(sf::Vector2f(-250, -100));
}
