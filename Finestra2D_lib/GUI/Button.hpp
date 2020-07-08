#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


class button : public sf::Drawable, sf::Transformable {

public:
    button();

    button(std::string buttonName, int x, int y, int height, int width, std::string texturePath) {
        setText(buttonName);
        setPos(x, y);
        setSize(height, width);
        setTexture(texturePath);
    }

    ~button();

    void setPos(int x, int y) {
        buttonSprite.setPosition(x, y);
        buttonText.setPosition(x + (buttonSprite.getLocalBounds().width / 4 - buttonText.getLocalBounds().width / 4),
                               y + (buttonSprite.getLocalBounds().height / 4 - buttonText.getLocalBounds().height / 4));
    }

    void setSize(float height, float width) {
        buttonSprite.setScale(height, width);
        buttonText.setScale(height, width);
    }

    void setTexture(std::string texturePath) {
        buttonRect = sf::IntRect(0, 0, rectWidth, rectHeight);
        buttonTexture.loadFromFile(texturePath);
        buttonSprite.setTexture(buttonTexture);
        buttonSprite.setTextureRect(buttonRect);
    }

    void setText(std::string buttonName) {
        buttonText.setString(buttonName);
        buttonFont.loadFromFile(NULL);
        buttonText.setCharacterSize(24);
        buttonText.setFont(buttonFont);
        buttonText.setOutlineThickness(2.0f);
        buttonText.scale(0.5f, 0.5f);
    }

    void setFont(std::string fontPath) {
        buttonFont.loadFromFile(fontPath);
    }

    void setFontFill(sf::Color chosenColor) {
        buttonText.setFillColor(chosenColor);
    }

    sf::FloatRect getBoundingBox() {
        return buttonSprite.getGlobalBounds();
    }

    float getSpriteWidth() { return buttonSprite.getGlobalBounds().width;}

    float getSpriteHeight() { return buttonSprite.getGlobalBounds().height; }


private:
    sf::Sprite buttonSprite;
    sf::Texture buttonTexture;
    sf::IntRect buttonRect;
    sf::Text buttonText;
    sf::Font buttonFont;
    bool hovered;
    int rectHeight = 49;
    int rectWidth = 190;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = &buttonTexture;
        target.draw(buttonSprite, states);
        target.draw(buttonText, states);
    }

};

#endif // !BUTTON_H
