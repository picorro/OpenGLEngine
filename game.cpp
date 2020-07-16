/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include "Game.h"
#include "resourceManager.h"
#include "spriteRenderer.h"
#include "gameObject.h";


// Game-related State data
SpriteRenderer* Renderer;


Game::Game(unsigned int width, unsigned int height)
	: State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
	delete Renderer;
	delete particleSpawner;
	FreeMemory();
}


void Game::Init()
{
	// load shaders
	ResourceManager::LoadShader("Shaders/sprite.vs", "Shaders/sprite.frag", nullptr, "sprite");
	// configure shaders
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width),
		static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
	// set render-specific controls
	Shader temp = ResourceManager::GetShader("sprite");
	Renderer = new SpriteRenderer(temp);
	// load textures
	ResourceManager::LoadTexture("Resources/awesomeface.png", true, "Resources/awesomeface.png");
	ResourceManager::LoadTexture("Resources/transparentface.png", true, "Resources/transparentface.png");
	levelManager.LoadLevel(objects, level1);
	//objects.push_back(new Particle("Resources/awesomeface.png", 0, 0, 500, 500, Vector2(10, 10), 0));
	objects.push_back(new ParticleSpawner("Resources/transparentface.png", 5, 1, 3, Vector2(-300, -300), Vector2(300, 300), -20, 20, 100, 150, 420, 250));
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Renderer = Renderer;
	}
}

void Game::Update(float dt)
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt);
	}
}

void Game::ProcessInput(float dt)
{

}
void Game::Render()
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Render();
	}
}
void Game::FreeMemory()
{
	for (int i = 0; i < objects.size(); i++)
	{
		delete(objects[i]);
	}
}