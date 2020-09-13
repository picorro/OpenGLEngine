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
	GameObject(float, float, float, float, float);
	//GameObject(std::string, float, float, float, float);/
	~GameObject();

	virtual void Render();
	virtual void Update(float);
	virtual void ProcessInput(float);

private:

};
