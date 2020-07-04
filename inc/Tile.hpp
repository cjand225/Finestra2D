#ifndef TILE_H
#define TILE_H

#define TILE_WIDTH 32
#define TILE_HEIGHT 32
#define TILE_SIZE 32
#define TILE_ZERO 0

#include <SFML/Graphics.hpp>


class tile : public sf::Drawable, public sf::Transformable {

public:
    tile() {}

    tile(int tileNum, float x, float y, int tilesize, sf::Texture *tileTexture) {
        tileID = tileNum;
        height = tilesize;
        width = tilesize;
        quadTexture = tileTexture;
        quadVerts.setPrimitiveType(sf::Quads);
        quadVerts.resize(4 * width);
        setVertexPos(x, y);
        quadTexture->setSmooth(true);
        scale(0.50f, 0.50f);
    }

    ~tile() {}

    void setVertexPos(int row, int collumn) {
        //Position coords
        quadVerts[0].position = sf::Vector2f(row * TILE_WIDTH, collumn * TILE_HEIGHT);
        quadVerts[1].position = sf::Vector2f((row + 1) * TILE_WIDTH, collumn * TILE_HEIGHT);
        quadVerts[2].position = sf::Vector2f((row + 1) * TILE_WIDTH, (collumn + 1) * TILE_HEIGHT);
        quadVerts[3].position = sf::Vector2f(row * TILE_WIDTH, (collumn + 1) * TILE_HEIGHT);

        //based on the dimensions of the actual texture
        setTexturePos(sf::Vector2f(2, 2), sf::Vector2f(30, 2), sf::Vector2f(30, 30), sf::Vector2f(2, 30));
    }

    void
    setTexturePos(sf::Vector2f firstPoint, sf::Vector2f secondPoint, sf::Vector2f thirdPoint,
                  sf::Vector2f fourthPoint) {

    }

private:
    sf::VertexArray quadVerts;
    sf::Texture *quadTexture;
    int tileID;
    float width;
    float height;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = quadTexture;
        target.draw(quadVerts, states);
    }
};


#endif // TILE_H

