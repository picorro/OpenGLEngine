#include "Particle.h";

Particle::Particle(std::string textureName, float pX, float pY, float sX, float sY, Vector2 velocity, float rotation, float timeLeftUntilDestruction): Sprite(textureName, pX, pY, sX, sY)
{
	this->velocity = velocity;
	this->rotation = rotation;
	this->timeLeftUntilDestruction = timeLeftUntilDestruction;
}

Particle::~Particle()
{
}

void Particle::Render()
{
	Texture2D sprite = ResourceManager::GetTexture(textureName);//I cannot create a Texture2D object cuz it crashes so I will leave it for now, this won't affect performance much anyway pls fix
	Renderer->DrawSprite(sprite,
		glm::vec2(transform.position.x, transform.position.y), glm::vec2(transform.scale.x, transform.scale.y), transform.rotation, glm::vec3(1.0f, 1.0f, 1.0f));
}

void Particle::Update(float dt)
{
	transform.position += velocity * dt;
	transform.rotation += rotation * dt;
	timeLeftUntilDestruction -= dt;
}