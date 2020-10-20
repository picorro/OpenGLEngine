#pragma once
#include <vector>
#include "Sprite.h";
#include "Tile.h";

class TileMap: public GameObject
{
	std::vector<Tile*> tiles;
public:
	TileMap(std::vector<Tile*>);
	TileMap();
	~TileMap();
	void Update(float);
	void Render();
};