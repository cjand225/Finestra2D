#include "../../inc/GUI/Menu.hpp"


menu::menu()
{

    //find size of array
    //make array items equal to the amount of text

    if(!font.loadFromFile(FONT_PATH)){

    }


}

menu::~menu()
{
    clearMen();
}

void menu::clearMen(){
    for(int i = 0; i < items; i++)
    {
        buttonList.pop_back();
    }
}

void menu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < items; i++ )
    {
        window.draw(buttonList[i]);
    }
}

void menu::setMenuType(int typeNum){
    mType = typeNum;
}


void menu::setMenuPos(sf::View currentView){

    int numOfButtons = buttonList.size();
    float centerX = currentView.getCenter().x;
    float centerY = currentView.getCenter().y;
    items = numOfButtons;


    for(int i = 0; i < numOfButtons; i++){

        buttonList[i].setFont(FONT_PATH);
        buttonList[i].setFontFill(sf::Color::White);
        buttonList[i].setText(itemList[i]);
        buttonList[i].setTexture(BUTTON_TEXTURE);

        switch(mType){
            case menuType::DropDown:
                buttonList[i].setPos(centerX, centerY);
                break;
            case menuType::Horizontal:
                spacing = buttonList[i].getSpriteHeight() * 2;
                buttonList[i].setPos(centerX + (i * spacing), centerY - buttonList[i].getSpriteWidth()/2);
                break;
            case menuType::Vertical:
                spacing = buttonList[i].getSpriteHeight() * 0.65f;
                buttonList[i].setPos(centerX - buttonList[i].getSpriteWidth()/2, centerY * 0.75f + (i * spacing));
                break;
            case menuType::LevelSelect:
                buttonList[i].setPos(centerX, centerY);
                break;
            default:
                buttonList[i].setPos(centerX, centerY);
                break;
        }


        buttonList[i].setSize(0.5f,0.5f);
    }

    buttonList[0].setFontFill(sf::Color::Blue);

    selectedItemIndex = 0;

}

//placeholder
void menu::setMenuItems(std::vector<std::string> menuItems){

    button tempButt;

    for(int i = 0; i < menuItems.size(); i++)
    {
        itemList.push_back(menuItems[i]);
        buttonList.push_back(tempButt);
    }

}

void menu::moveUp()
{
    if(selectedItemIndex - 1 >= 0)
    {
        buttonList[selectedItemIndex].setFontFill(sf::Color::White);
        selectedItemIndex--;
        buttonList[selectedItemIndex].setFontFill(sf::Color::Blue);
    }
}

void menu::moveDown()
{
    if(selectedItemIndex + 1 < items)
    {

        buttonList[selectedItemIndex].setFontFill(sf::Color::White);
        selectedItemIndex++;
        buttonList[selectedItemIndex].setFontFill(sf::Color::Blue);
    }
}

//used specifically for Levelselect
void menu::moveRight()
{
    if(selectedItemIndex + 1 < items)
    {
        buttonList[selectedItemIndex].setFontFill(sf::Color::White);
        selectedItemIndex += (items / 2);
        buttonList[selectedItemIndex].setFontFill(sf::Color::Blue);
    }
}

//used specifically for Levelselect
void menu::moveLeft()
{

    // -1 from index
    if(selectedItemIndex - 1 >= 0)
    {
        buttonList[selectedItemIndex].setFontFill(sf::Color::White);
        selectedItemIndex -= items/2;
        buttonList[selectedItemIndex].setFontFill(sf::Color::Blue);

    }

}



sf::FloatRect menu::getButtonBB(int buttonNum){
    return buttonList[buttonNum].getBoundingBox();
}

