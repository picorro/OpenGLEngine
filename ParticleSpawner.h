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
	ParticleSpawner(std::string textureName, int spawnRate,
		float minimalParticleLifeTime, float maximalParticleLifeTime,
		Vector2 minimalVelocity, Vector2 maximalVelocity,
		float minimalRotationSpeed, float maximalRotationSpeed,
		int minimalParticleSize, int maximalParticleSize,
		float x, float y);
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

	void Update(float dt, std::vector<GameObject*>& objects);
	void Render();
private:
	float timeUntilNextSpawn;
};