#pragma once
#include <vector>;
#include <fstream>;
#include "GameObject.h";
#include "Sprite.h";
#include "ParticleSpawner.h";
#include "TileMap.h";
#include "Tile.h";

class LevelManager
{
	void LoadTileMap(std::ifstream& file, std::vector<GameObject*>& vec, SpriteRenderer* Renderer);
	void LoadParticleSpawner(std::ifstream& file, std::vector<GameObject*>& vec);
public:
	LevelManager();
	~LevelManager();
	std::string currentLevel = "";
	void LoadLevel(std::vector<GameObject*>& vec, std::string fileName, SpriteRenderer* Renderer);
	void SaveLevel(std::vector<GameObject*>& vec, std::string fileName);
	void ClearLevel();
};
