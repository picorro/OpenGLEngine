#pragma once
#include <iostream>;
#include "Sprite.h";
#include "PhysicsBody.h";
#include "RectangleCollider.h";
#include "Entity.h";

class Player: public Entity
{
public:
	Player(std::string textureName, float pX, float pY, float sX, float sY, float rotation, float movementSpeed);
	~Player();
	PhysicsBody physicsBody = nullptr;
	RectangleCollider rectangleCollider = nullptr;
	std::string textureName;
	float movementSpeed;

	void Update(float dt);
	void Render();
};

