#pragma once
#include "Entity.h";
#include "Component.h";
#include <vector>;
#include "Vector2.h";



class RectangleCollider: public Component
{
public:
	RectangleCollider(GameObject*);
	~RectangleCollider();
	
	void Update(float);
	std::vector<Vector2> GetRectangle();
};