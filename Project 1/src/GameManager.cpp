#include "GameManager.h"
#include "Scenes/Scene.h"
#include "Scenes/MainMenuScene.h"
#include "Scenes/GameScene.h"

GameManager::GameManager() : m_window(sf::VideoMode(1200, 800), "Parachute Panic")
{
    m_mainMenuScene = new MainMenuScene();
    m_gameScene = new GameScene();

    m_currentScene = m_mainMenuScene;
}

GameManager::~GameManager()
{
    delete m_mainMenuScene;
    delete m_gameScene;
    delete m_currentScene;
}

void GameManager::run()
{
    while (m_window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void GameManager::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_window.close();
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);

                if (m_currentScene == m_mainMenuScene) {
                    MainMenuScene* menuScene = dynamic_cast<MainMenuScene*>(m_currentScene);
                    if (menuScene) {
                        for (Button& button : menuScene->GetButtons()) {
                            if (button.isMouseOver(mousePosition)) {
                                button.handleClick();
                                break;  // Exit the loop after handling the click for the first matching button
                            }
                        }
                    }
                }
            }
        }
        // Process other events (e.g., keyboard input) here
    }
}

void GameManager::update()
{
}

void GameManager::render()
{
    m_window.clear();
    if (m_currentScene)
        m_currentScene->Draw(m_window);
    m_window.display();
}
