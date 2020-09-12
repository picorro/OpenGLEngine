#include "TileMap.h"

TileMap::TileMap()
{
}

TileMap::~TileMap()
{
}

void TileMap::Update(float dt)
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
