#include "LevelManager.h";

LevelManager::LevelManager()
{

}

LevelManager::~LevelManager()
{

}

void LevelManager::LoadLevel(std::vector<GameObject*>& vec, std::string fileName)
{
	ClearLevel();
	std::ifstream file((fileName));
	std::string str;

	std::map<int, std::string> map; // number corresponding to texture name in file
	int textureCount = 0;
	int textureWidth = 0, textureHeight = 0;
	int mapHeight = 0, mapWidth = 0;

	std::cout << "Checking " << fileName << std::endl;
	while (file >> str) //TO DO add bools to make it not check with string every time cuz its prolly slow (f.e. if (bool && str == std::string))
	{
		if (str == "TileMap") // this will load create and add objects to the go vector according to the data in file
		{					  // data in file must follow a standard, because errors not handled //TO DO HANDLE ERRORS
			std::cout << "TileMap found.\n";
			while (file >> str) // string is not supported in switch :'(
			{
				if (str == "TextureCount")
				{
					file >> str; // enters count
					textureCount = atoi(str.c_str());
					std::cout << "\t" << textureCount << " Texture(s) found.\n";
					for (int i = 0; i < textureCount; i++)
					{
						file >> str; // enters texture number
						int temp = atoi(str.c_str());
						file >> str; // enters texture name
						map.insert(std::pair<int, std::string>(temp, str));
					}
					for (auto it = map.begin(); it != map.end(); it++)
					{
						std::cout << "\t\t" << it->first << " " << it->second << "\n";
					}
				}
				else if (str == "TextureWidth")
				{
					file >> str;
					textureWidth = atoi(str.c_str());
					printf("\tTextureWidth: %d\n", textureWidth);
				}
				else if (str == "TextureHeight")
				{
					file >> str;
					textureHeight = atoi(str.c_str());
					printf("\tTextureHeight: %d\n", textureHeight);
				}
				else if (str == "MapHeight")
				{
					file >> str;
					mapHeight = atoi(str.c_str());
					printf("\tMapHeight: %d\n", mapHeight);
				}
				else if (str == "MapWidth")
				{
					file >> str;
					mapWidth = atoi(str.c_str());
					printf("\tMapWidth: %d\n", mapWidth);
				}
				else if (str == "EndOfParameters")
					break;
			}
		}
		for (int i = 0; i < mapWidth; i++)
		{
			printf("\n");
			for (int j = 0; j < mapHeight; j++)
			{
				file >> str;
				std::cout << str << " ";
				auto it = map.find(atoi(str.c_str()));
				if(it != map.end())
					vec.push_back(new Sprite(map[atoi(str.c_str())], textureWidth * i, textureHeight * j, textureWidth, textureHeight));
			}
		}
	}
}
void LevelManager::SaveLevel(std::vector<GameObject*>& vec, std::string fileName)
{

}

void LevelManager::ClearLevel()
{

}
