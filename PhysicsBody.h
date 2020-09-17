#pragma once
#include "Transform.h";
#include "Vector2.h";
#include "Entity.h";
#include "Component.h";

class PhysicsBody: public Component
{
public:
	PhysicsBody(Entity*);
	~PhysicsBody();

	void Update(float);
	Vector2 velocity;
};

