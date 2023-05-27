#pragma once
#include "Scene.h";

class GameScene : public Scene
{
public:
    GameScene();
    void Update() override;
    void Draw(sf::RenderWindow& window) override;

private:
    sf::RectangleShape rectangle;

};

