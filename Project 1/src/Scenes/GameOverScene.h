#pragma once
#include "Scene.h"
#include <functional>
#include "../Button.h"

class GameOverScene : public Scene
{
public:
    GameOverScene();
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;

    void AddButton(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& fillColor, std::function<void()> onClick);
    std::vector<Button> GetButtons();

private:
    void SetTitleText();

    std::vector<Button> m_buttons;

    sf::Font m_titleFont;
    sf::Text m_titleText;
    sf::Text m_highScoreText;
};

