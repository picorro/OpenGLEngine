#pragma once
#include "GameObject.h";

class Entity: public GameObject
{
public:
	Entity(float pX, float pY, float sX, float sY, float rotation, bool hasCollider);
};

