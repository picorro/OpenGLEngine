#pragma once
#include "Vector2.h";
#include <vector>
class Transform
{
public:
	Transform();
	Transform(float pX, float pY, float sX, float sY, float rotation);
	~Transform();
	Vector2 position;
	Vector2 scale;
	float rotation;
	std::vector<Vector2> GetRectangle();
private:

};
