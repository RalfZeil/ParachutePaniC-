#pragma once
#include <SFML/Graphics.hpp>
#include "Scenes/Scene.h"

static class GameManager
{
private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow m_window;

public:
    GameManager(GameManager& other) = delete;
    void operator=(const GameManager&) = delete;

    static GameManager* GetInstance();

    Scene* m_currentScene;
    Scene* m_mainMenuScene;
    Scene* m_gameScene;

    GameManager();
    ~GameManager();
    void run();
    void ChangeScene(Scene* scene);

};