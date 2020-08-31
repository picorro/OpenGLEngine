#include "Transform.h";

Transform::Transform()
{
	position.x = 0;
	position.y = 0;
	scale.x = 0;
	scale.y = 0;
	rotation = 0;
}
Transform::Transform(float pX, float pY, float sX, float sY, float rotation)
{
	position.x = pX;
	position.y = pY;
	scale.x = sX;
	scale.y = sY;
	this->rotation = rotation;
}

Transform::~Transform()
{

}