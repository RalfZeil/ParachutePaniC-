#pragma once
#include "GameObject.h"
#include <iostream>

class Player : public GameObject
{
private:
	float speed;
	float acceleration = 0;
	float force = 0;
	float friction = 0;
	float deltaForce = 0;
	float mass = 30;

public:
	Player(float x, float y, Scene* scene);
	void Start() override;
	void Update(float dt) override;
	virtual void Collision(GameObject* other) override;
};

