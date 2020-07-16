#pragma once
#include "Vector2.h";
#include "Sprite.h";

class Particle: public Sprite
{
public:
	Particle(std::string, float, float, float, float, Vector2, float, float);
	~Particle();
	Vector2 velocity;
	float rotation;
	float timeLeftUntilDestruction;
	void Render();
	void Update(float);
private:

};
