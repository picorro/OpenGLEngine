#pragma once
#include "Sprite.h";
#include "RectangleCollider.h"
class Tile: public Sprite
{
public:
	Tile(std::string textureName, float pX, float pY, float sX, float sY, float rotation, bool hasCollider);
	~Tile();
	RectangleCollider rectangleCollider = nullptr;
};

