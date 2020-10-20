#pragma once
#include "Vector2.h";
class Transform
{
public:
	Transform();
	Transform(float pX, float pY, float sX, float sY, float rotation);
	~Transform();
	Vector2 position;
	Vector2 scale;
	float rotation;

private:

};
