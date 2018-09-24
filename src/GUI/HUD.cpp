#include "../../inc/GUI/HUD.hpp"



UI::UI()
{
    if(!font.loadFromFile(FONT_PATH)){
	}

	loadTextures();


}

UI::~UI(){

}

void UI::updatePos(float centerX, float centerY){

    //updates score
    for(int i = MAX_SCORE_PLACE; i > 0; i--){
        scoreSprites[i].setPosition(((centerX - (2 * (SCORE_SPACING * MAX_SCORE_PLACE) /3) + (SCORE_SPACING * i))), (centerY/12));    //center - width of objects + spacing
    }

    //updates lives
    for(int i = 0; i < MAX_LIVES; i++){
        livesSprite[i].setPosition(((centerX/ 32 ) + (LIFE_SPACING * i)), (centerY/12));        //1/4 of center + spacing in X, 1/8 of Center in Y
    }
    //updates ammo


    //updates abilities

}

void UI::draw(sf::RenderWindow &window){
    for(int i = MAX_SCORE_PLACE; i > 0; i--){
        window.draw(scoreSprites[i]);
    }
    for(int i = 0; i < MAX_LIVES; i++){
        window.draw(livesSprite[i]);
    }
}

std::string UI::intToString(int number){
    std::ostringstream strs;
    strs << number;
    std::string str = strs.str();

    return str;
}

std::string UI::fltToString(float score){
    std::ostringstream strs;
    strs << score;
    std::string str = strs.str();
    return str;
}


void UI::loadTextures(){

    loadScoreTextures(UI_SCORE_PATH);
    loadLifeTextures(UI_HEALTH_PATH);
    //loadActionTextures();

}

void UI::loadActionTextures(std::string actionPath){

	for (int i = 0; i < MAX_ACTIONS; i++) {
		sf::Texture newTexture;
		newTexture.loadFromFile(actionPath + std::to_string(i) + ".png");
		actionTextures[i] = newTexture;
	}

}

void UI::loadLifeTextures(std::string lifePath){

	for (int i = 0; i < MAX_LIVES; i++) {
		sf::Texture newTexture;
		newTexture.loadFromFile(lifePath + std::to_string(i) + ".png");
		lifeTextures[i] = newTexture;
	}
}

void UI::loadScoreTextures(std::string scorePath){

	for (int i = 0; i < MAX_SCORE_TEXTURE; i++) {
		sf::Texture newTexture;
		newTexture.loadFromFile(scorePath + std::to_string(i) + ".png");
		scoreTextures[i] = newTexture;
	}

}

void UI::updateScore(int score){

    int tempScore = score;
    int counter = MAX_SCORE_PLACE - 1;
    int numOfDigits = 0;
    int digitBase = 10;
    int tempDigit = 0;

    //updates textures based on sprites
    for(int i = MAX_SCORE_PLACE; i > 0; i--){
            tempDigit = tempScore % digitBase;

            scoreSprites[i].setTexture(scoreTextures[tempDigit]);
            scoreSprites[i].setTextureRect(sf::IntRect(0, 0, (int)scoreTextures[tempDigit].getSize().x, (int)scoreTextures[tempDigit].getSize().y));
            scoreSprites[i].setScale(0.45f, 0.45f);

            counter -= 1;
            tempScore /= digitBase;
    }
}

void UI::updateLives(double lives){

    //0     - 1st empty, 2nd empty, 3rd empty
    //.5    - 1st half,  2nd empty, 3rd empty
    //1     - 1st whole, 2nd empty, 3rd empty
    //1.5   - 1st whole, 2nd half, 3rd empty
    //2.5   - 1st whole, 2nd whole, 3rd half
    //3.0   - 1st whole, 2nd whole, 3rd whole

    int tempLives = lives;

    for(int i = 0; i < MAX_LIVES; i++){
            livesSprite[i].setTexture(lifeTextures[i]);
            livesSprite[i].setTextureRect(sf::IntRect(0, 0, (int)lifeTextures[i].getSize().x, (int)lifeTextures[i].getSize().y));
            livesSprite[i].setScale(0.25f, 0.25f);
    }


}

void UI::setPosition(float x, float y, float width, float height){

}
