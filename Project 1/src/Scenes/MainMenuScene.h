#pragma once
#include "Scene.h";
#include <functional>
#include "../Button.h"

class MainMenuScene : public Scene
{
public:
    MainMenuScene();
    void Update() override;
    void Draw(sf::RenderWindow& window) override;

    void AddButton(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& fillColor, std::function<void()> onClick);
    std:: vector<Button> GetButtons();

private:
    std::vector<Button> m_buttons;
};

