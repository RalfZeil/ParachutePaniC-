#pragma once
#include "GameObject.h"
#include <iostream>

class Player : public GameObject
{
public:
	Player(float x, float y, Scene* scene);
	void Start() override;
	void Update(float dt) override;
	virtual void Collision(GameObject* other) override;
};

