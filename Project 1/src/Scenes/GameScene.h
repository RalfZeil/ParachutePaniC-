#pragma once
#include "Scene.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Enemy.h"
#include "../GameObjects/EnemySpawner.h"

class GameScene : public Scene
{
public:
    GameScene();
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;

private:
    Player* player;
    Enemy* enemy;
    EnemySpawner* enemySpawner;
};

