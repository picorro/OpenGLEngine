#pragma once
#include "Entity.h";
#include "Component.h";
class RectangleCollider: public Component
{
public:
	RectangleCollider(Entity*);
	~RectangleCollider();
};

