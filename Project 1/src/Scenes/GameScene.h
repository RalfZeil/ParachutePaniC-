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
    void OnSceneLoad() override;

    Player* player;
    EnemySpawner* enemySpawner;

private:
    int m_score = 0;
    
    float m_timePerPoint = 1;
    float m_scoreTimer = m_timePerPoint;

    sf::Font m_font;
    sf::Text m_scoreCounter;
};

