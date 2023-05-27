#include "GameManager.h"

int main() {
    GameManager* gameManager = GameManager::GetInstance();

    gameManager->run();

    return 0;
}