#pragma once
#include "GameObject.h"
class Player : public GameObject
{
private:
	float speed;

public:
	Player(float x, float y);
	void Start() override;
	void Update() override;
};

