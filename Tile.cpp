#include "Tile.h"

Tile::Tile(std::string textureName, float pX, float pY, float sX, float sY, float rotation): Sprite(textureName, pX, pY, sX, sY, rotation)
{
	rectangleCollider = RectangleCollider(this);
}

Tile::~Tile()
{

}
