#pragma once
#include "Scene.h";

class GameScene : public Scene
{
private:
    sf::RectangleShape rect;

public:
    GameScene();
    void Update() override;
    void Draw(sf::RenderWindow& window) override;
};

