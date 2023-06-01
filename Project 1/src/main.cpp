#include "GameManager.h"

int main() {
    auto gameManager = GameManager::GetInstance();

    gameManager->run();

    return 0;
} 