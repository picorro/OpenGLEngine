#pragma once
#include "Transform.h"
#include "Vector2.h"
#include "Entity.h"
#include "Component.h"
#include "RectangleCollider.h"

class PhysicsBody: public Component
{
public:
	PhysicsBody(GameObject* parent, float mass, bool useGravity);
	PhysicsBody();
	~PhysicsBody();
	void Update(float dt, std::vector<GameObject*>& objects);
	void AddForce(Vector2 force);

	RectangleCollider collider;
	Vector2 velocity;
	Vector2 acceleration;
	float mass;
	bool useGravity;
};

