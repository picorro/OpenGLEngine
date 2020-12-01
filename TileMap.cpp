#include "TileMap.h"

TileMap::TileMap(std::vector<Tile*> tiles)
{
	this->tiles = tiles;
}

TileMap::TileMap()
{

}

TileMap::~TileMap()
{
}

void TileMap::Update(float dt, std::vector<GameObject*>& objects)
{
	for (int i = 0; i < tiles.size(); i++)
	{
		tiles[i]->Update(dt);
	}
}

void TileMap::Render()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		tiles[i]->Render();
	}
}
