#pragma once
#include <iostream>;
#include "Sprite.h";
#include "PhysicsBody.h";
#include "Entity.h";

class Player: public Entity
{
public:
	Player(std::string, float, float, float, float, float, float);
	~Player();
	PhysicsBody physicsBody = nullptr;
	std::string textureName;
	float movementSpeed;

	void Update(float);
	void Render();
};

