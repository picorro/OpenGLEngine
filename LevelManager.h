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
public:
	LevelManager();
	~LevelManager();
	std::string currentLevel = "";
	void LoadLevel(std::vector<GameObject*>&, std::string, SpriteRenderer*);
	void SaveLevel(std::vector<GameObject*>&, std::string);
	void LoadTileMap(std::ifstream&, std::vector<GameObject*>&, SpriteRenderer*);
	void LoadParticleSpawner(std::ifstream&, std::vector<GameObject*>&);
	void ClearLevel();
private:

};
