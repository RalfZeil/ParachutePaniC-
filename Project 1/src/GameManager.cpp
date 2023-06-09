#include "GameManager.h"
#include "Scenes/Scene.h"
#include "Scenes/MainMenuScene.h"
#include "Scenes/GameScene.h"
#include "Scenes/GameOverScene.h"
#include <memory>;

GameManager *GameManager::GetInstance()
{
    static GameManager* Instance;
    if (Instance == nullptr) {
        Instance = new GameManager();
    }
    return Instance;
}

GameManager::GameManager() : m_window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),  WINDOW_TITLE)
{
    m_mainMenuScene = new MainMenuScene();
    m_gameScene = new GameScene();
    m_gameOverScene = new GameOverScene();
    m_currentScene = m_mainMenuScene;
}

GameManager::~GameManager()
{
    delete m_mainMenuScene;
    delete m_gameScene;
    delete m_gameOverScene;
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

void GameManager::ChangeScene(Scene* scene)
{
    m_currentScene = scene;
    m_currentScene->OnSceneLoad();
}

void GameManager::SubmitScore(int score)
{
    if (score > highScore) 
    {
        highScore = score;
    }
}

int GameManager::GetHighScore()
{
    return highScore;
}

void GameManager::processEvents()
{
    //Handle button clicks
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

                if (m_currentScene == m_gameOverScene) {
                    GameOverScene* menuScene = dynamic_cast<GameOverScene*>(m_currentScene);
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
    }
}

//Update all the gameobjects in the scene
void GameManager::update()
{
    if (m_currentScene) {

        //Get delta time to pass to Update()
        float dt = clock.restart().asSeconds();

        m_currentScene->Update(dt);
        m_currentScene->DetectCollision();
    }
}

//Render all objects in the scene
void GameManager::render()
{
    m_window.clear();

    if (m_currentScene)
        m_currentScene->Draw(m_window);

    m_window.display();
}
