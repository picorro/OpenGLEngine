/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include "game.h"
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
}


void Game::Init()
{
	objects.push_back(GameObject("face", 0, 0, 100, 100));
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
	ResourceManager::LoadTexture("Resources/awesomeface.png", true, "face");
	objects[0].Renderer = Renderer;
}

void Game::Update(float dt)
{
	
}

void Game::ProcessInput(float dt)
{

}
void Game::Render()
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i].Render();
	}
}