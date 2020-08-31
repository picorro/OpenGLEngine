#pragma once
#include "GameObject.h";
#include <iostream>;

class Sprite: public GameObject
{
public:
	std::string textureName;
	Sprite(std::string, float, float, float, float, float);
	~Sprite();
	void Render();
	void Update(float);

private:

};
