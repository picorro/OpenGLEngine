#pragma once
#include <iostream>
#include <vector>
#include "Transform.h"
#include "resourceManager.h"
#include "SpriteRenderer.h"

//static Texture2D sprite;
class GameObject
{
public:
	int ID;
	std::string name;
	Transform transform;
	SpriteRenderer* Renderer = nullptr;
	bool hasCollider;

	GameObject();
	GameObject(bool hasCollider);
	GameObject(float pX, float pY, float sX, float sY, float rotation);
	GameObject(float pX, float pY, float sX, float sY, float rotation, bool hasCollider);
	~GameObject();

	virtual void Render();
	virtual void Update(float dt, std::vector<GameObject*>& objects);


private:

};
