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

void RectangleCollider::Update(float dt, std::vector<GameObject*>& objects)
{

}

bool RectangleCollider::IsColliding(std::vector<Vector2> other)
{
	std::vector<Vector2> rect = parent->transform.GetRectangle();
	if (rect[1].x > other[0].x && rect[0].x < other[1].x)
		if (rect[2].y > other[0].y && rect[0].y < rect[2].y)
			return true;
	return false;
}