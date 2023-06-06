#pragma once
#include "GameObject.h"
#include <list>
#include "Enemy.h"

class EnemySpawner : public GameObject
{
private:
	float spawnDelay = 2.f;
	float spawnDelayAmount = 2.f;

public:
	EnemySpawner(float x, float y, Scene* scene);
	void Start() override;
	void Update(float dt) override;
};

