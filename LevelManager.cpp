#include "LevelManager.h";
static enum stringValue
{
	EndOfParameters, //TileMap, ParticleSpawner
	X, Y, //TileMap, ParticleSpawner
	TextureCount, // TileMap, ParticleSpawner
	TileMapENUM,
		TextureWidth,
		TextureHeight,
		MapHeight,
		MapWidth,
	ParticleSpawnerENUM,
		SpawnRate,
		MinimalParticleLifetime,
		MaximalParticleLifetime,
		MinimalVelocity,
		MaximalVelocity,
		MinimalRotationSpeed,
		MaximalRotationSpeed,
		MinimalParticleSize,
		MaximalParticleSize
};

static std::map<std::string, stringValue> stringMap;

void prepareMap()
{
	stringMap.insert(std::pair<std::string, stringValue>("EndOfParameters", EndOfParameters));
	stringMap.insert(std::pair<std::string, stringValue>("TileMap", TileMapENUM));
	stringMap.insert(std::pair<std::string, stringValue>("ParticleSpawner", ParticleSpawnerENUM));
	stringMap.insert(std::pair<std::string, stringValue>("TextureCount", TextureCount));
	stringMap.insert(std::pair<std::string, stringValue>("TextureWidth", TextureWidth));
	stringMap.insert(std::pair<std::string, stringValue>("TextureHeight", TextureHeight));
	stringMap.insert(std::pair<std::string, stringValue>("MapHeight", MapHeight));
	stringMap.insert(std::pair<std::string, stringValue>("MapWidth", MapWidth));
	stringMap.insert(std::pair<std::string, stringValue>("X", X));
	stringMap.insert(std::pair<std::string, stringValue>("Y", Y));
	stringMap.insert(std::pair<std::string, stringValue>("SpawnRate", SpawnRate));
	stringMap.insert(std::pair<std::string, stringValue>("MinimalParticleLifetime", MinimalParticleLifetime));
	stringMap.insert(std::pair<std::string, stringValue>("MaximalParticleLifetime", MaximalParticleLifetime));
	stringMap.insert(std::pair<std::string, stringValue>("MinimalVelocity", MinimalVelocity));
	stringMap.insert(std::pair<std::string, stringValue>("MaximalVelocity", MaximalVelocity));
	stringMap.insert(std::pair<std::string, stringValue>("MinimalRotationSpeed", MinimalRotationSpeed));
	stringMap.insert(std::pair<std::string, stringValue>("MaximalRotationSpeed", MaximalRotationSpeed));
	stringMap.insert(std::pair<std::string, stringValue>("MinimalParticleSize", MinimalParticleSize));
	stringMap.insert(std::pair<std::string, stringValue>("MaximalParticleSize", MaximalParticleSize));

}

LevelManager::LevelManager()
{
	prepareMap();
}

LevelManager::~LevelManager()
{

}

void LevelManager::SaveLevel(std::vector<GameObject*>& vec, std::string fileName)
{

}

void LevelManager::ClearLevel()
{

}
void LevelManager::LoadLevel(std::vector<GameObject*>& vec, std::string fileName, SpriteRenderer* Renderer)
{
	ClearLevel();
	std::ifstream file((fileName));
	std::string str;

	std::cout << "Checking " << fileName << std::endl;

	while (file >> str)
	{
		if (stringMap.find(str) != stringMap.end())
		{
			switch (stringMap[str])
			{
			case TileMapENUM:
				LoadTileMap(file, vec, Renderer);
				break;
			
			case ParticleSpawnerENUM:
				LoadParticleSpawner(file, vec);
				break;
			}
		}
	}
}
void LevelManager::LoadTileMap(std::ifstream &file, std::vector<GameObject*>& vec, SpriteRenderer* Renderer)
{
	std::map<int, std::string> map; // texture name corresponding to number
	int textureCount = 0;
	int textureWidth = 0, textureHeight = 0;
	int mapHeight = 0, mapWidth = 0;
	int x = 0, y = 0;
	std::string str;
	bool readComplete = false;
	printf("TileMap found!\n");
	while (file >> str)
	{
		if (stringMap.find(str) != stringMap.end())
		{
			switch (stringMap[str])
			{
			case TextureCount:
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
				break;
			case TextureWidth:
				file >> str;
				textureWidth = atoi(str.c_str());
				printf("\tTextureWidth: %d\n", textureWidth);
				break;
			case TextureHeight:
				file >> str;
				textureHeight = atoi(str.c_str());
				printf("\tTextureHeight: %d\n", textureHeight);
				break;
			case MapHeight:
				file >> str;
				mapHeight = atoi(str.c_str());
				printf("\tMapHeight: %d\n", mapHeight);
				break;
			case MapWidth:
				file >> str;
				mapWidth = atoi(str.c_str());
				printf("\tMapWidth: %d\n", mapWidth);
				break;
			case X:
				file >> str;
				x = atoi(str.c_str());
				printf("\tX: %d\n", x);
				break;
			case Y:
				file >> str;
				y = atoi(str.c_str());
				printf("\tY: %d\n", y);
				break;
			case EndOfParameters:
				std::vector<Tile*> tileVector;
				for (int i = 0; i < mapWidth; i++) // read the actual map now that all parameters have been set and create the game objects
				{
					for (int j = 0; j < mapHeight; j++)
					{
						file >> str;
						auto it = map.find(atoi(str.c_str()));
						if (it != map.end())
						{
							Tile* tempTile = new Tile(map[atoi(str.c_str())], x + textureWidth * i, y + textureHeight * j, textureWidth, textureHeight, 0, true);
							tileVector.push_back(tempTile);
							vec.push_back(tempTile);
						}
					}
				}
				for (int i = 0; i < tileVector.size(); i++)
				{
					tileVector[i]->Renderer = Renderer;
				}
				TileMap* tileMap = new TileMap(tileVector);
				vec.push_back(tileMap);
				std::cout << "\tTileMap should contain " << mapHeight * mapWidth << " tiles\n";
				readComplete = true;
				break;
			}
		}
		if (readComplete)
			break;
	}
}
void LevelManager::LoadParticleSpawner(std::ifstream& file, std::vector<GameObject*>& vec)
{

	std::map<int, std::string> map;
	int textureCount = 0;
	int spawnRate = 1, minimalParticleSize = 0, maximalParticleSize = 0, x = 0, y = 0;
	Vector2 minimalVelocity(0, 0);
	Vector2 maximalVelocity(0, 0);
	float minimalRotationSpeed = 0, maximalRotationSpeed = 0, minimalParticleLifetime = 0, maximalParticleLifetime = 0;
	std::string str;
	float tempX = 0, tempY = 0;
	printf("ParticleSpawner Found!\n");
	while (file >> str)
	{
		if (stringMap.find(str) != stringMap.end())
		{
			switch (stringMap[str])
			{
			case TextureCount:
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
				break;
			case SpawnRate:
				file >> str;
				spawnRate = atoi(str.c_str());
				printf("\tSpawnRate: %d\n", spawnRate);
				break;
			case MinimalParticleLifetime:
				file >> str;
				minimalParticleLifetime = atoi(str.c_str());
				printf("\tMinimalParticleLifetime: %f\n", minimalParticleLifetime);
				break;
			case MaximalParticleLifetime:
				file >> str;
				maximalParticleLifetime = atoi(str.c_str());
				printf("\tMaximalParticleLifetime: %f\n", maximalParticleLifetime);
				break;
			case MinimalVelocity:
				file >> str;
				tempX = atoi(str.c_str());
				file >> str;
				tempY = atoi(str.c_str());
				minimalVelocity = Vector2(tempX, tempY);
				printf("\tMinimalVelocity: [%f; %f]\n", minimalVelocity.x, minimalVelocity.y);
				break;
			case MaximalVelocity:
				file >> str;
				tempX = atoi(str.c_str());
				file >> str;
				tempY = atoi(str.c_str());
				maximalVelocity = Vector2(tempX, tempY);
				printf("\tMaximalVelocity: [%f; %f]\n", maximalVelocity.x, maximalVelocity.y);
				break;
			case MinimalRotationSpeed:
				file >> str;
				minimalRotationSpeed = atoi(str.c_str());
				printf("\tMinimalRotationSpeed: %f\n", minimalRotationSpeed);
				break;
			case MaximalRotationSpeed:
				file >> str;
				maximalRotationSpeed = atoi(str.c_str());
				printf("\tMaximalRotationSpeed: %f\n", maximalRotationSpeed);
				break;
			case MinimalParticleSize:
				file >> str;
				minimalParticleSize = atoi(str.c_str());
				printf("\tMinimalParticleSize: %d\n", minimalParticleSize);
				break;
			case MaximalParticleSize:
				file >> str;
				maximalParticleSize = atoi(str.c_str());
				printf("\tMaximalParticleSize: %d\n", maximalParticleSize);
				break;
			case X:
				file >> str;
				x = atoi(str.c_str());
				printf("\tX: %d\n", x);
				break;
			case Y:
				file >> str;
				y = atoi(str.c_str());
				printf("\tY: %d\n", y);
				break;
			case EndOfParameters:
				vec.push_back(new ParticleSpawner("Resources/transparentface.png", spawnRate,
					minimalParticleLifetime, maximalParticleLifetime,
					minimalVelocity, maximalVelocity,
					minimalRotationSpeed, maximalRotationSpeed,
					minimalParticleSize, maximalParticleSize,
					x, y));
				break;
			}
		}
	}
}