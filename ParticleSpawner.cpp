#include "ParticleSpawner.h";

ParticleSpawner::ParticleSpawner(std::string textureName, int spawnRate,
	float minimalParticleLifeTime, float maximalParticleLifeTime,
	Vector2 minimalVelocity, Vector2 maximalVelocity,
	float minimalRotationSpeed, float maximalRotationSpeed,
	int minimalParticleSize, int maximalParticleSize,
	float x, float y): GameObject(x, y, 0, 0, 0)
{
	this->textureName = textureName;
	this->spawnRate = spawnRate;
	this->minimalParticleLifeTime = minimalParticleLifeTime;
	this->maximalParticleLifeTime = maximalParticleLifeTime;
	this->minimalVelocity = minimalVelocity;
	this->maximalVelocity = maximalVelocity;
	this->minimalRotationSpeed = minimalRotationSpeed;
	this->maximalRotationSpeed = maximalRotationSpeed;
	this->minimalParticleSize = minimalParticleSize;
	this->maximalParticleSize = maximalParticleSize;
	timeUntilNextSpawn = 0;
	srand(time(NULL));
}

ParticleSpawner::~ParticleSpawner()
{
	for (int i = 0; i < particles.size(); i++)
	{
		delete(particles[i]);
	}
}

void ParticleSpawner::Update(float dt)
{
	timeUntilNextSpawn -= dt;
	if (timeUntilNextSpawn <= 0) //SPOOOWN
	{
		int size = rand() % (maximalParticleSize - minimalParticleSize + 1) + minimalParticleSize;
		Particle* temp = new Particle(textureName, transform.position.x, transform.position.y,
			size, size,
			rand() % 360,
			Vector2(rand() % (int)(maximalVelocity.x - minimalVelocity.x + 1) + (int)minimalVelocity.x,
			rand() % (int)(maximalVelocity.y - minimalVelocity.y + 1) + (int)minimalVelocity.y),
			rand() % (int)(maximalRotationSpeed - minimalRotationSpeed + 1) + (int)minimalRotationSpeed,
			rand() % (int)(maximalParticleLifeTime - minimalParticleLifeTime + 1) + (int)minimalParticleLifeTime);
		temp->Renderer = Renderer;
		particles.push_back(temp);
		timeUntilNextSpawn = 1.0 / spawnRate;
	}
	for (int i = 0; i < particles.size(); i++)
	{
		if (particles[i]->timeLeftUntilDestruction <= 0)
		{
			particles.erase(particles.begin() + i);
		}
		particles[i]->Update(dt);
	}
}

void ParticleSpawner::Render()
{
	for (int i = 0; i < particles.size(); i++)
	{
		particles[i]->Render();
	}
}
