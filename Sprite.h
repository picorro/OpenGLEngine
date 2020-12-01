#pragma once
#include "GameObject.h";
#include <iostream>;

class Sprite: public GameObject
{
public:
	std::string textureName;
	Sprite(std::string textureName, float pX, float pY, float sX, float sY, float rotation);
	Sprite(std::string textureName, float pX, float pY, float sX, float sY, float rotation, bool hasCollider);
	~Sprite();
	void Render();
	void Update(float dt);

private:

};
