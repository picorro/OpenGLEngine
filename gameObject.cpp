#include "gameObject.h";
GameObject::GameObject()
{

}
GameObject::GameObject(float pX, float pY, float sX, float sY): transform(pX, pY, sX, sY)
{
	ID = 0;
}
/*GameObject::GameObject(std::string texName, float pX, float pY, float sX, float sY) : transform(pX, pY, sX, sY)
{
	textureName = texName;
}*/


GameObject::~GameObject()
{

}
void GameObject::Render()
{
	
}
void GameObject::Update()
{
}