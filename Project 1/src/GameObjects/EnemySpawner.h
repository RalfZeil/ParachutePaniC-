#pragma once
#include "GameObject.h"
#include <list>
#include "Enemy.h"

class EnemySpawner : public GameObject
{
private:
	std::list<GameObject*> &gameSceneGameObjects;

public:
	EnemySpawner(float x, float y, std::list<GameObject*> &gameSceneGameObjectsList);
	void Start() override;
	void Update(float dt) override;
};

