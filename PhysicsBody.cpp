#include "PhysicsBody.h"

PhysicsBody::PhysicsBody(Entity* parent): Component(parent)
{

}

PhysicsBody::~PhysicsBody()
{

}

void PhysicsBody::Update(float dt)
{
	parent->transform.position.x += velocity.x * dt;
	parent->transform.position.y += velocity.y * dt;
}
