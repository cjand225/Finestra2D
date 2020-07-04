#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.hpp"

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class TileMap {
public:
    TileMap();

    ~TileMap() {
        for (int i = 0; i < tileCount - 1; i++) {
            delete tilesetMap[i];
            tilesetMap.pop_back();
        }
        tilesetMap.clear();
    }

    void renderTiles(sf::RenderWindow &window, int x) {
        //glorified loop of tile draws
        for (int i = 0; i < width * height; i++) {
            window.draw(*tilesetMap[i]);
        }
    }

    void loadArray(std::string filePath) {
        //Loads array from CSV file
        std::string cell;
        std::vector<int> tempVect;
        std::vector<std::vector<int>> tempMatrix;

        std::ifstream data(filePath);
        std::string line;
        int lineNum = 0;
        int numOfNum = 0;

        while (std::getline(data, line)) {
            tempVect.clear();
            std::stringstream lineStream(line);
            std::string cell;
            while (std::getline(lineStream, cell, ',')) {
                int tempNum = std::stoi(cell);
                tempVect.push_back(tempNum);
                numOfNum++;


            }
            tempMatrix.push_back(tempVect);
            lineNum++;
        }

        width = numOfNum / lineNum;
        height = lineNum;
        tileMapCoords = tempMatrix;
    }

    void loadTileTextures(std::string tilesetPath, int tileNum) {
        //loads texture files into indexed array (vector)
        for (int i = 0; i < tileNum; i++) {
            sf::Texture newTexture;
            newTexture.loadFromFile(tilesetPath + std::to_string(i) + ".png");
            tilesetTextures.push_back(newTexture);
        }
    }

    void loadMap() {

    }                                                  //NYI
    void load() {
        //Loads Tiles onto vector
        if (loaded) {
            return;
        } else {
            //Populate Vector with Tile Objects based on height and width of map - uses map stored in csv but in a mirrored ordered
            int counter = 0;
            for (int i = 0; i < width; i++) {
                for (int j = 0; j < height; j++) {
                    sf::Texture *tempTexture = &tilesetTextures[tileMapCoords[j][i]];
                    tile *tempTile = new tile(counter, i, j, TILE_SIZE, tempTexture);
                    tilesetMap.push_back(tempTile);
                    counter++;
                }
            }
            loaded = true;
        }
    }

    sf::IntRect getBoundingBox(int num);                                    //gets BB for collision checks
    std::vector<tile *> *returnPtr() { return &tilesetMap; }

private:

    bool loaded = false;
    int width;
    int height;
    float tileWidth = TILE_WIDTH;
    float tileHeight = TILE_HEIGHT;
    int tileCount = 0;
    std::vector<tile *> tilesetMap;
    std::vector<sf::Texture> tilesetTextures;
    std::vector<std::vector<int>> tileMapCoords;


};

#endif // TILEMAP_H
