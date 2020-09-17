#pragma once
#include "Entity.h";
class Component
{
public:
	Entity* parent = nullptr;
	Component(Entity*);
	~Component();
};

