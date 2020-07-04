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





//Base UI position based on Bounding box of Render Window +/- the Width/height difference of each element

class UI {
public:
    UI() {
        if (!font.loadFromFile(NULL)) {
        }

        loadTextures();


    }

    ~UI();

    static std::string intToString(int number) {
        std::ostringstream strs;
        strs << number;
        std::string str = strs.str();

        return str;
    }

    std::string fltToString(float score) {
        std::ostringstream strs;
        strs << score;
        std::string str = strs.str();
        return str;
    }


    void loadTextures() {

        loadScoreTextures(NULL);
        loadLifeTextures(NULL);
        //loadActionTextures();
    }

    void loadScoreTextures(std::string scorePath) {
        for (int i = 0; i < MAX_SCORE_TEXTURE; i++) {
            sf::Texture newTexture;
            newTexture.loadFromFile(scorePath + std::to_string(i) + ".png");
            scoreTextures[i] = newTexture;
        }

    }

    void loadLifeTextures(std::string lifePath) {
        for (int i = 0; i < MAX_LIVES; i++) {
            sf::Texture newTexture;
            newTexture.loadFromFile(lifePath + std::to_string(i) + ".png");
            lifeTextures[i] = newTexture;
        }
    }

    void loadActionTextures(std::string actionPath) {
        for (int i = 0; i < MAX_ACTIONS; i++) {
            sf::Texture newTexture;
            newTexture.loadFromFile(actionPath + std::to_string(i) + ".png");
            actionTextures[i] = newTexture;
        }

    }

    //info gets pulled from player class
    void updateAmmoSpecial(int ammoSpecial) {}

    void updateAmmoCount(int ammoCount) {}

    void updateLives(double lives) {
        //0     - 1st empty, 2nd empty, 3rd empty
        //.5    - 1st half,  2nd empty, 3rd empty
        //1     - 1st whole, 2nd empty, 3rd empty
        //1.5   - 1st whole, 2nd half, 3rd empty
        //2.5   - 1st whole, 2nd whole, 3rd half
        //3.0   - 1st whole, 2nd whole, 3rd whole

        int tempLives = lives;

        for (int i = 0; i < MAX_LIVES; i++) {
            livesSprite[i].setTexture(lifeTextures[i]);
            livesSprite[i].setTextureRect(
                    sf::IntRect(0, 0, (int) lifeTextures[i].getSize().x, (int) lifeTextures[i].getSize().y));
            livesSprite[i].setScale(0.25f, 0.25f);
        }
    }

    void updateScore(int score) {
        int tempScore = score;
        int counter = MAX_SCORE_PLACE - 1;
        int numOfDigits = 0;
        int digitBase = 10;
        int tempDigit = 0;

        //updates textures based on sprites
        for (int i = MAX_SCORE_PLACE; i > 0; i--) {
            tempDigit = tempScore % digitBase;

            scoreSprites[i].setTexture(scoreTextures[tempDigit]);
            scoreSprites[i].setTextureRect(sf::IntRect(0, 0, (int) scoreTextures[tempDigit].getSize().x,
                                                       (int) scoreTextures[tempDigit].getSize().y));
            scoreSprites[i].setScale(0.45f, 0.45f);

            counter -= 1;
            tempScore /= digitBase;
        }
    }


    void setPosition(float x, float y, float width, float height) {}  //takes bounding box of sf::View
    void updatePos(float centerX, float centerY) {
        //updates score
        for (int i = MAX_SCORE_PLACE; i > 0; i--) {
            scoreSprites[i].setPosition(((centerX - (2 * (SCORE_SPACING * MAX_SCORE_PLACE) / 3) + (SCORE_SPACING * i))),
                                        (centerY / 12));    //center - width of objects + spacing
        }

        //updates lives
        for (int i = 0; i < MAX_LIVES; i++) {
            livesSprite[i].setPosition(((centerX / 32) + (LIFE_SPACING * i)),
                                       (centerY / 12));        //1/4 of center + spacing in X, 1/8 of Center in Y
        }
        //updates ammo


        //updates abilities

    }

    void draw(sf::RenderWindow &window) {
        for (int i = MAX_SCORE_PLACE; i > 0; i--) {
            window.draw(scoreSprites[i]);
        }
        for (int i = 0; i < MAX_LIVES; i++) {
            window.draw(livesSprite[i]);
        }
    }


private:
    //base ui position on view pos
    sf::Font font;
    int xSpace = 15;

    //Sprites for Action/score/lives
    sf::Sprite ScoreTextSprite;                            //text associated with score
    sf::Sprite lifeTextSprite;                             //text associated with Lives

    sf::Sprite livesSprite[MAX_LIVES];                     //only 3 lives, so 3 sprites
    sf::Sprite scoreSprites[MAX_SCORE_PLACE];              //variable could be 0 to 1,000,000 - Make assumption these are min/max - 7 sprites
    sf::Sprite actionSprites[MAX_ACTIONS];                 //contains only 1 attack and 1 secondary attack

    //Textures for Action/score/lives
    sf::Texture scoreTextures[MAX_SCORE_TEXTURE];           //assume 0-9 for textures - 10 textures only
    sf::Texture lifeTextures[MAX_LIVES];                    //empty - half - full, 3 states - so 3 textures
    sf::Texture actionTextures[MAX_ACTIONS];                //assumes only 2 actions so two textures

    sf::Font uiFont;

};

#endif // UI_H
