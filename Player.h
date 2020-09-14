#pragma once
#include <iostream>
#include "Sprite.h"
#include "PhysicsBody.h"

class Player: public GameObject
{
public:
	Player(std::string, float, float, float, float, float, float);
	~Player();
	PhysicsBody physicsBody;
	std::string textureName;
	float movementSpeed;

	void Update(float);
	void Render();
};

