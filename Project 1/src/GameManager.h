#pragma once
#include <SFML/Graphics.hpp>
#include "Scenes/Scene.h"

static class GameManager
{
public:
    GameManager();
    ~GameManager();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow m_window;

    // Other member variables, such as player, obstacles, power-ups, etc.

    Scene* m_currentScene;
    Scene* m_mainMenuScene;
    Scene* m_gameScene;
};