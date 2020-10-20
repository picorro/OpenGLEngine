#pragma once
#include "Sprite.h";
#include "RectangleCollider.h"
class Tile: public Sprite
{
public:
	Tile(std::string, float, float, float, float, float);
	~Tile();
	RectangleCollider rectangleCollider = nullptr;
};

