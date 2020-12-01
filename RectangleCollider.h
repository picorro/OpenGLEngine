#pragma once
#include "Entity.h"
#include "Component.h"
#include <vector>
#include "Vector2.h"



class RectangleCollider: public Component
{
public:
	RectangleCollider(GameObject* parent);
	RectangleCollider();
	~RectangleCollider();
	
	void Update(float dt, std::vector<GameObject*>& objects);
	bool IsColliding(std::vector<Vector2> other);
};