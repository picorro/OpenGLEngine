#pragma once
#include <glad.h>
#include <glfw3.h>
#include "resourceManager.h";
#include "spriteRenderer.h";
#include "Vector2.h";
#include "gameObject.h";
#include <vector>;
#include <algorithm>;
#include <iostream>;
#include "Sprite.h";
#include "LevelManager.h";
#include "ParticleSpawner.h";
#include "Player.h"

const std::string level1 = "Levels/Level1.txt";

enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};
class Game
{
public:
	std::vector<GameObject*> objects;
	LevelManager levelManager;
	ParticleSpawner* particleSpawner;
	Player* player = new Player("Resources/transparentface.png", 0, 0, 50, 50, 0, 100);

	//GameObject object;
	// game state
	GameState    State;
	bool         Keys[1024];
	unsigned int Width, Height;
	// constructor/destructor
	Game(unsigned int width, unsigned int height);
	~Game();
	// initialize game state (load all shaders/textures/levels)
	void Init();
	// game loop
	void ProcessInput();
	void Update(float dt);
	void Render();
	void FreeMemory();
};
