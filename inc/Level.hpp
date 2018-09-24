#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include "Tilemap.hpp"
#include "Character.hpp"

struct  level;
class   levelManager;

struct Level{
	//level num
	int ID;
	int numOfTiles;
	int numOfEnemies;
	int numOfPlayers;
	int numOfLives;
	int* TileArray;
	//strings for audio and sound effects
	std::string audioPath;
	std::string* soundEffects;
	int numOfSounds;
};

class   levelManager{
    public:

    private:
};

#endif

