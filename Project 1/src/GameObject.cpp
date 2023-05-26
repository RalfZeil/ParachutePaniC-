#include "GameObject.h"
#include "GameManager.h"

GameObject::GameObject(std::string texLocation, float size)
{
	collider.ChangeRadius(size);
	objectTexture.loadFromFile(texLocation);
	//GameManager::AddNewGameObject(this);
}

void GameObject::Start()
{
}

void GameObject::Update()
{
}
