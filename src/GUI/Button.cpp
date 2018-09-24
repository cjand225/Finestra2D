#include "../../inc/GUI/Button.hpp"

button::button() {

}

button::button(std::string buttonName,int x, int y, int height, int width, std::string texturePath) {

    setText(buttonName);
	setPos(x,y);
	setSize(height, width);
	setTexture(texturePath);

}

button::~button() {

}

void button::setPos(int x, int y) {
	buttonSprite.setPosition(x, y);
	buttonText.setPosition(x + (buttonSprite.getLocalBounds().width/4 - buttonText.getLocalBounds().width/4), y + (buttonSprite.getLocalBounds().height/4 - buttonText.getLocalBounds().height/4));
}

void button::setTexture(std::string texturePath) {
	buttonRect = sf::IntRect(0, 0, rectWidth, rectHeight);
	buttonTexture.loadFromFile(texturePath);
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setTextureRect(buttonRect);

}

void button::setSize(float height, float width) {
	buttonSprite.setScale(height, width);
	buttonText.setScale(height,width);
}

void button::setText(std::string buttonName){
    buttonText.setString(buttonName);
    buttonFont.loadFromFile(FONT_PATH);
    buttonText.setCharacterSize(24);
    buttonText.setFont(buttonFont);
    buttonText.setOutlineThickness(2.0f);
    buttonText.scale(0.5f,0.5f);
}

void button::setFont(std::string fontPath){
    buttonFont.loadFromFile(fontPath);
}

void button::setFontFill(sf::Color chosenColor){
    buttonText.setFillColor(chosenColor);
}

sf::FloatRect button::getBoundingBox(){
    return buttonSprite.getGlobalBounds();
}

float button::getSpriteWidth(){
    return buttonSprite.getGlobalBounds().width;
}

float button::getSpriteHeight(){
    return buttonSprite.getGlobalBounds().height;
}
