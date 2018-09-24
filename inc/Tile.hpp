#ifndef TILE_H
#define TILE_H

#define TILE_WIDTH 32
#define TILE_HEIGHT 32
#define TILE_SIZE 32
#define TILE_ZERO 0

#include <SFML/Graphics.hpp>


class tile : public sf::Drawable, public sf::Transformable {

	public:
		tile() { }
		tile(int tileNum, float x, float y, int tilesize, sf::Texture* tileset);
		~tile();

		void	setVertexPos(int row, int collumn);
		void    setTexturePos(sf::Vector2f firstPoint, sf::Vector2f secondPoint, sf::Vector2f thirdPoint, sf::Vector2f fourthPoint);

	private:
		sf::VertexArray		quadVerts;
		sf::Texture*		quadTexture;
		int			tileID;
		float			width;
		float			height;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
			states.transform *= getTransform();
			states.texture = quadTexture;
			target.draw(quadVerts, states);
		}
};


#endif // TILE_H

