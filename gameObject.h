#pragma once
#include <iostream>;
#include "Transform.h";
#include "resourceManager.h";
#include "SpriteRenderer.h";

//static Texture2D sprite;
class GameObject
{
public:
	int ID;
	std::string name;
	Transform transform;
	SpriteRenderer* Renderer = nullptr;

	GameObject();
	GameObject(float pX, float pY, float sX, float sY, float rotation);
	~GameObject();

	virtual void Render();
	virtual void Update(float);

private:

};
