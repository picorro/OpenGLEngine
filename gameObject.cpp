#include "gameObject.h";
GameObject::GameObject()
{
	hasCollider = false;
}
GameObject::GameObject(bool hasCollider)
{
	this->hasCollider = hasCollider;
}
GameObject::GameObject(float pX, float pY, float sX, float sY, float rotation): transform(pX, pY, sX, sY, rotation)
{
	ID = 0;
	hasCollider = false;
}
GameObject::GameObject(float pX, float pY, float sX, float sY, float rotation, bool hasCollider) : transform(pX, pY, sX, sY, rotation)
{
	ID = 0;
	this->hasCollider = hasCollider;
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
void GameObject::Update(float dt, std::vector<GameObject*>& objects)
{

}
