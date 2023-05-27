#pragma once
#include "Scene.h"
#include "../GameObjects/Player.h"

class GameScene : public Scene
{
public:
    GameScene();
    void Update() override;
    void Draw(sf::RenderWindow& window) override;

private:
    Player *player;
};

