#include "PhysicsBody.h"

PhysicsBody::PhysicsBody(GameObject* parent, float mass, bool useGravity): Component(parent)
{
	this->useGravity = useGravity;
	this->mass = mass;
	collider = RectangleCollider(parent);
}

PhysicsBody::PhysicsBody(): mass(0), useGravity(false)
{
	
}

PhysicsBody::~PhysicsBody()
{

}

void PhysicsBody::Update(float dt, std::vector<GameObject*>& objects)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->hasCollider && objects[i] != parent)
		{
			if (collider.IsColliding(objects[i]->transform.GetRectangle()))
				return;
		}
	}
	if (useGravity)
		AddForce(Vector2(0, 9.8 * mass));
	velocity += acceleration;
	acceleration.Reset();
	parent->transform.position.x += velocity.x * dt;
	parent->transform.position.y += velocity.y * dt;
}

void PhysicsBody::AddForce(Vector2 force)
{
	acceleration += Vector2(force.x / mass, force.y / mass);
}
