#pragma once
#include "Vector2.h";
class Transform
{
public:
	Transform();
	Transform(float, float, float, float);
	~Transform();
	Vector2 position;
	Vector2 scale;
	float rotation;

private:

};
