#include "../../inc/GUI/Cursor.hpp"

cursor::cursor(){

}

cursor::cursor(std::string texturePath){

    setTexture(texturePath);


}

cursor::~cursor(){

}

void cursor::setPos(sf::RenderWindow* window){
    mCursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));

}

void cursor::setTexture(std::string texturePath){

	cursorTexture.loadFromFile(texturePath);
	mCursor.setTexture(cursorTexture);
	mCursor.setTextureRect(textureRect);
	mCursor.scale(0.55f, 0.55f);
}



