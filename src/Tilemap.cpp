#include "../inc/Tilemap.hpp"

tilemap::tilemap(){

}

tilemap::~tilemap(){
    for(int i = 0; i < tileCount - 1; i++)
    {
        delete tilesetMap[i];
		tilesetMap.pop_back();
    }
    tilesetMap.clear();
}

void tilemap::loadTileTextures(std::string tilesetPath, int tileNum) {

	for (int i = 0; i < tileNum; i++) {
		sf::Texture newTexture;
		newTexture.loadFromFile(tilesetPath + std::to_string(i) + ".png");
		tilesetTextures.push_back(newTexture);
	}

	//std::cout << tilesetTextures.size() << std::endl;

}

void tilemap::load()
{
	if (loaded == true){
		return;
	}
	else{
        //Populate Vector with Tile Objects based on height and width of map - uses map stored in csv but in a mirrored ordered
        int counter = 0;
        for (int i = 0; i < width; i++){
            for (int j = 0; j < height; j++){
                sf::Texture* tempTexture = &tilesetTextures[tileMapCoords[j][i]];
                tile *tempTile = new tile(counter, i, j, TILE_SIZE, tempTexture);
                tilesetMap.push_back(tempTile);
                counter++;
            }
		}
		loaded = true;
	}
}

void tilemap::renderTiles(sf::RenderWindow &window, int x){
    for (int i = 0; i < width*height; i ++){
        window.draw(*tilesetMap[i]);
    }
}

std::vector<tile*>* tilemap::returnPtr(){
	return &tilesetMap;
}

void tilemap::loadArray(std::string filePath){


    std::string                     cell;
    std::vector<int>                tempVect;
    std::vector<std::vector<int>>   tempMatrix;

    std::ifstream                   data(filePath);
    std::string                     line;
    int                             lineNum = 0;
    int                             numOfNum = 0;

    while(std::getline(data,line))
    {
        tempVect.clear();
        std::stringstream  lineStream(line);
        std::string        cell;
        while(std::getline(lineStream,cell,','))
        {
            int tempNum = std::stoi(cell);
            tempVect.push_back(tempNum);
            numOfNum++;


        }
        tempMatrix.push_back(tempVect);
        lineNum++;
    }

    width = numOfNum/lineNum;
    height = lineNum;
    tileMapCoords = tempMatrix;

}
