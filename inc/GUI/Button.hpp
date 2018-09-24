#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../prefix.hpp"


class button : public sf::Drawable , sf::Transformable {

	public:
		button();
		button(std::string buttonName, int x, int y, int height, int width, std::string texturePath);
		~button();

		void 		setPos(int x, int y);
		void 		setSize(float height, float width);
		void 		setTexture(std::string texturePath);
		void 		setText(std::string buttonName);
		void 		setFont(std::string fontPath);
		void 		setFontFill(sf::Color chosenColor);
	       	sf::FloatRect 	getBoundingBox();
		float 		getSpriteWidth();
        	float 		getSpriteHeight();




	private:
		sf::Sprite 	buttonSprite;
		sf::Texture 	buttonTexture;
		sf::IntRect 	buttonRect;
		sf::Text 	buttonText;
		sf::Font 	buttonFont;
		bool 		hovered;
		int 		rectHeight = 49;
		int 		rectWidth = 190;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
			states.transform *= getTransform();
			states.texture = &buttonTexture;
			target.draw(buttonSprite, states);
			target.draw(buttonText,states);
		}

};

#endif // !BUTTON_H
