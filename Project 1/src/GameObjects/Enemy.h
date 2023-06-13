#pragma once
#include "GameObject.h"
class Enemy : public GameObject
{
private:
	float m_stateTimer = 0;
	int m_state = 0; //0 dont move, 1 move left, 2 move right

public:
	Enemy(float x, float y, Scene* scene);
	void Start() override;
	void Update(float dt) override;
};

