#pragma once
#include "GameData.h"
#include <SFML/Graphics.hpp>
#include "Scenes/Scene.h"


class GameManager
{
private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow m_window;
    sf::Clock clock;

    int highScore;

public:
    GameManager(GameManager& other) = delete;
    void operator=(const GameManager&) = delete;

    static GameManager* GetInstance();

    Scene* m_currentScene;
    Scene* m_mainMenuScene;
    Scene* m_gameOverScene;
    Scene* m_gameScene; 

    GameManager();
    ~GameManager();
    void run();
    void ChangeScene(Scene* scene);
    void SubmitScore(int score);
    int GetHighScore();

};