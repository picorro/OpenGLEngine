#pragma once
#include <iostream>
#include "Sprite.h"

class Player: public GameObject
{
public:
	Player(std::string, float, float, float, float, float);
	~Player();
	std::string textureName;
	void Update(float);
	void Render();
	void ProcessInput(float);
};

