#ifndef TILEMAP_H
#define TILEMAP_H


#include "prefix.hpp"
#include "Tile.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class tilemap
{
	public:
        tilemap();
        ~tilemap();

        void			renderTiles(sf::RenderWindow &window, int x);               //glorified loop of tile draws
        void			loadArray(std::string filePath);                            //Loads array from CSV file
	void 			loadTileTextures(std::string tilesetPath, int tileNum);     //loads texture files into indexed array (vector)
        void 			loadMap();                                                  //NYI
        void 			load();                                                     //Loads Tiles onto vector
	sf::IntRect		getBoundingBox(int num);                                    //gets BB for collision checks
        std::vector<tile*>*	returnPtr();

	private:

	bool				loaded 		= false;
        int				width;
	int				height;
	float				tileWidth 	= TILE_WIDTH;
	float				tileHeight 	= TILE_HEIGHT;
        int				tileCount       = 0;
        std::vector<tile*>		tilesetMap;
	std::vector<sf::Texture>	tilesetTextures;
	std::vector<std::vector<int>>   tileMapCoords;


};

#endif // TILEMAP_H
