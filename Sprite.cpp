#include "Sprite.h";

Sprite::Sprite(std::string texName, float pX, float pY, float sX, float sY) : GameObject(pX, pY, sX, sY)
{
	textureName = texName;
}

Sprite::~Sprite()
{
}

void Sprite::Render()
{
	Texture2D sprite = ResourceManager::GetTexture(textureName);//I cannot create a Texture2D object cuz it crashes so I will leave it for now, this won't affect performance much anyway pls fix
	Renderer->DrawSprite(sprite,
		glm::vec2(transform.position.x, transform.position.y), glm::vec2(transform.scale.x, transform.scale.y), transform.rotation, glm::vec3(1.0f, 1.0f, 1.0f));
}

void Sprite::Update()
{

}
