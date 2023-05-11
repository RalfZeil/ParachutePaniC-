#pragma once
#include "GameObject.h"
#include <string>
using namespace std;

class Player : GameObject
{
public:
	Player(float radius, string textureLocation);
};

