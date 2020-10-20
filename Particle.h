#pragma once
#include "Vector2.h";
#include "Sprite.h";

class Particle: public Sprite
{
public:
	Particle(std::string textureName, float pX, float pY, float sX, float sY, float rotation, Vector2 velocity, float rotationSpeed, float timeLeftUntilDestruction);
	~Particle();
	Vector2 velocity;
	float rotationSpeed;
	float timeLeftUntilDestruction;
	void Render();
	void Update(float);
private:

};
