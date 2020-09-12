#pragma once
#include <vector>
#include "Sprite.h"

class TileMap: public GameObject
{
	std::vector<Sprite*> tiles; // should be tiles not sprites
public:
	TileMap();
	~TileMap();
	void Update(float);
	void Render();
};