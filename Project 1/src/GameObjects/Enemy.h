#pragma once
#include "GameObject.h"
class Enemy : public GameObject
{
public:
	Enemy(float x, float y, Scene* scene);
	void Start() override;
	void Update(float dt) override;
};

