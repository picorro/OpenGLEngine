#include "Tile.h"

Tile::Tile(std::string textureName, float pX, float pY, float sX, float sY, float rotation, bool hasCollider): Sprite(textureName, pX, pY, sX, sY, rotation, hasCollider)
{
	rectangleCollider = RectangleCollider(this);
}

Tile::~Tile()
{

}
