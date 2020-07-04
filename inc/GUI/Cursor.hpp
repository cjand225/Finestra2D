#ifndef CURSOR_H
#define CURSOR_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <utility>

class cursor;

class cursor : public sf::Drawable, public sf::Transformable {
public:
    cursor();

    cursor(std::string texturePath) {
        setTexture(std::move(texturePath));
    }

    ~cursor();

    void setTexture(std::string texturePath) {
        cursorTexture.loadFromFile(texturePath);
        mCursor.setTexture(cursorTexture);
        mCursor.setTextureRect(textureRect);
        mCursor.scale(0.55f, 0.55f);
    }

    void setPos(sf::RenderWindow *window) {
        mCursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));
    }

    void setMouse(sf::Mouse *mPtr);

private:
    sf::Sprite mCursor;
    sf::Texture cursorTexture;

    sf::IntRect textureRect = sf::IntRect(0, 0, 16, 16);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = &cursorTexture;
        target.draw(mCursor, states);
    }
};


#endif // CURSOR_H
