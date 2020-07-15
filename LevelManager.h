#pragma once
#include <vector>;
#include <fstream>;
#include "GameObject.h";
#include "Sprite.h";
class LevelManager
{
public:
	LevelManager();
	~LevelManager();
	std::string currentLevel = "";
	void LoadLevel(std::vector<GameObject*>&, std::string);
	void SaveLevel(std::vector<GameObject*>&, std::string);
	void ClearLevel();
private:

};
