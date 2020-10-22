#include "RectangleCollider.h"
RectangleCollider::RectangleCollider(GameObject* parent): Component(parent)
{

}

RectangleCollider::RectangleCollider()
{

}

RectangleCollider::~RectangleCollider()
{

}

void RectangleCollider::Update(float dt)
{

}

std::vector<Vector2> RectangleCollider::GetRectangle()
{
	std::vector<Vector2> vec // returns corners {0,0  1,0  0,1  1,1}
	{ 
		Vector2 (parent->transform.position.x, parent->transform.position.y),
		Vector2 (parent->transform.position.x + parent->transform.scale.x, parent->transform.position.y),
		Vector2 (parent->transform.position.x, parent->transform.position.y + parent->transform.position.x + parent->transform.scale.y),
		Vector2 (parent->transform.position.x + parent->transform.position.x + parent->transform.scale.x, parent->transform.position.y + parent->transform.position.x + parent->transform.scale.y)
	};
	return vec;
}