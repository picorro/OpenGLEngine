#pragma once
#include <iostream>;
#include "Transform.h";
#include "resourceManager.h";
#include "spriteRenderer.h";

//static Texture2D sprite;
class GameObject
{
public:
	std::string name;
	Transform transform;
	SpriteRenderer* Renderer = nullptr;
	std::string textureName;
	GameObject();
	GameObject(std::string, float, float, float, float);
	~GameObject();
	void Render();
	void Update();

private:

};
