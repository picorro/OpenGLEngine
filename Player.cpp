#include "Player.h"

Player::Player(std::string textureName, float pX, float pY, float sX, float sY, float rotation) : GameObject(pX, pY, sX, sY, rotation)
{
	this->textureName = textureName;
}

Player::~Player()
{

}

void Player::Update(float dt)
{

}
void Player::Render()
{
	Texture2D sprite = ResourceManager::GetTexture(textureName);//I cannot create a Texture2D object cuz it crashes so I will leave it for now, this won't affect performance much anyway pls fix
	Renderer->DrawSprite(sprite,
		glm::vec2(transform.position.x, transform.position.y), glm::vec2(transform.scale.x, transform.scale.y), transform.rotation, glm::vec3(1.0f, 1.0f, 1.0f));
}

void Player::ProcessInput(float dt)
{

}