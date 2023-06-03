#pragma once
#include "GameObject.h"
class Enemy : public GameObject
{
private:
	float speed;
	float acceleration = 0;
	float force = 0;
	float friction = 0;
	float deltaForce = 0;
	float mass = 30;

public:
	Enemy(float x, float y);
	void Start() override;
	void Update(float dt) override;
};

