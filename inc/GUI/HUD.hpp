#ifndef UI_H
#define UI_H

#define MAX_ACTIONS 2
#define MAX_SCORE_PLACE 7
#define MAX_LIVES 3

#define MAX_SCORE_TEXTURE 10

#define LIFE_SPACING 15
#define SCORE_SPACING 14
#define ACTION_SPACING 20


#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "../prefix.hpp"



//Base UI position based on Bounding box of Render Window +/- the Width/height difference of each element


class UI;

class UI
{
    public:
        UI();
        ~UI();

	std::string	intToString(int number);
	std::string	fltToString(float score);


        void            loadTextures();
        void            loadScoreTextures(std::string scorePath);
        void            loadLifeTextures(std::string lifePath);
        void            loadActionTextures(std::string actionPath);

        //info gets pulled from player class
        void            updateAmmoSpecial(int ammoSpecial);
        void            updateAmmoCount(int ammoCount);
        void            updateLives(double lives);
        void            updateScore(int score);


        void            setPosition(float x, float y, float width, float height);   //takes bounding box of sf::View
        void		updatePos(float centerX, float centerY);
        void		draw(sf::RenderWindow &window);




	private:
		//base ui position on view pos
		sf::Font	font;
		int 		xSpace = 15;

       		//Sprites for Action/score/lives
        	sf::Sprite  ScoreTextSprite;                            //text associated with score
        	sf::Sprite  lifeTextSprite;                             //text associated with Lives

        	sf::Sprite  livesSprite[MAX_LIVES];                     //only 3 lives, so 3 sprites
        	sf::Sprite  scoreSprites[MAX_SCORE_PLACE];              //variable could be 0 to 1,000,000 - Make assumption these are min/max - 7 sprites
        	sf::Sprite  actionSprites[MAX_ACTIONS];                 //contains only 1 attack and 1 secondary attack
        
		//Textures for Action/score/lives
        	sf::Texture scoreTextures[MAX_SCORE_TEXTURE];           //assume 0-9 for textures - 10 textures only
        	sf::Texture lifeTextures[MAX_LIVES];                    //empty - half - full, 3 states - so 3 textures
        	sf::Texture actionTextures[MAX_ACTIONS];                //assumes only 2 actions so two textures

        	sf::Font    uiFont;

};
#endif // UI_H
