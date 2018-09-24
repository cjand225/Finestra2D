#ifndef CURSOR_H
#define CURSOR_H

#include "../prefix.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class cursor;

class cursor: public sf::Drawable, public sf::Transformable {
    public:
        cursor();
        cursor(std::string texturePath);
        ~cursor();

        void setTexture(std::string texturePath);
        void setPos(sf::RenderWindow* window);
        void setMouse(sf::Mouse* mPtr);

    private:
        sf::Sprite  mCursor;
        sf::Texture cursorTexture;

        sf::IntRect textureRect = sf::IntRect(0, 0, 16, 16);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
			states.transform *= getTransform();
			states.texture = &cursorTexture;
			target.draw(mCursor, states);
		}
};



#endif // CURSOR_H
