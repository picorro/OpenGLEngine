#pragma once
#include "Entity.h";
class Component
{
public:
	GameObject* parent = nullptr;
	Component(GameObject*);
	~Component();
	virtual void Update(float) {};
};

