#pragma once
/// <summary>
/// Has its own vector of particles and manages them in Update loop;
/// </summary>
#include <iostream>;
#include "Vector2.h";
#include "Sprite.h";
#include <vector>;
#include <stdlib.h> 
#include <time.h>   
#include "Particle.h";
#include "SpriteRenderer.h";

class ParticleSpawner: public GameObject
{
public:
	ParticleSpawner(std::string, int, float, float, Vector2, Vector2, float, float, int, int, float, float);
	~ParticleSpawner();
	std::vector<Particle*> particles;
	std::string textureName;
	int spawnRate;
	float minimalParticleLifeTime;
	float maximalParticleLifeTime;
	Vector2 minimalVelocity;
	Vector2 maximalVelocity;
	float minimalRotationSpeed;
	float maximalRotationSpeed;
	int minimalParticleSize;
	int maximalParticleSize;

	void Update(float dt);
	void Render();
private:
	float timeUntilNextSpawn;
};