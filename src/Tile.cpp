#include "../inc/Tile.hpp"




tile::tile(int tileNum, float x, float y, int tilesize,sf::Texture* tileTexture){
    tileID = tileNum;
    height = tilesize;
    width = tilesize;
    quadTexture = tileTexture;
    quadVerts.setPrimitiveType(sf::Quads);
    quadVerts.resize(4 * width);
    setVertexPos(x,y);
    quadTexture->setSmooth(true);
    scale(0.50f,0.50f);

}


tile::~tile(){

   // delete this;

}

void tile::setVertexPos(int row, int collumn){

		//Position coords
        quadVerts[0].position = sf::Vector2f(row * TILE_WIDTH, collumn * TILE_HEIGHT);
        quadVerts[1].position = sf::Vector2f((row + 1) * TILE_WIDTH, collumn * TILE_HEIGHT);
        quadVerts[2].position = sf::Vector2f((row + 1) * TILE_WIDTH, (collumn + 1) * TILE_HEIGHT);
        quadVerts[3].position = sf::Vector2f(row * TILE_WIDTH, (collumn + 1) * TILE_HEIGHT);

        //based on the dimensions of the actual texture
        setTexturePos(sf::Vector2f(2,2),sf::Vector2f(30,2),sf::Vector2f(30,30),sf::Vector2f(2,30));

}

void tile::setTexturePos(sf::Vector2f firstPoint, sf::Vector2f secondPoint, sf::Vector2f thirdPoint, sf::Vector2f fourthPoint){

        quadVerts[0].texCoords = firstPoint;
        quadVerts[1].texCoords = secondPoint;
        quadVerts[2].texCoords = thirdPoint;
        quadVerts[3].texCoords = fourthPoint;
}
