#pragma once
#include "GameObject.h"
#include <list>
#include "Enemy.h"

class EnemySpawner : public GameObject
{
private:
	float spawnDelay = 0.5f;
	float spawnDelayAmount = 0.5f;

public:
	EnemySpawner(float x, float y, Scene* scene);
	void Start() override;
	void Update(float dt) override;
};

