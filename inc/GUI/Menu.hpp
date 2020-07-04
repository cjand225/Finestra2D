#ifndef MENU_H
#define MENU_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Button.hpp"

enum menuType {

    LevelSelect,
    Vertical,
    DropDown,
    Horizontal

};

class menu {
public:
    menu() {
        if (!font.loadFromFile(NULL)) {

        }

    }

    ~menu() {
        clearMen();
    }

    //new updated version of menu
    void setMenuItems(std::vector<std::string> menuItems) {
        button tempButt;

        for (int i = 0; i < menuItems.size(); i++) {
            itemList.push_back(menuItems[i]);
            buttonList.push_back(tempButt);
        }
    }

    void setMenuPos(sf::View currentView) {

        int numOfButtons = buttonList.size();
        float centerX = currentView.getCenter().x;
        float centerY = currentView.getCenter().y;
        items = numOfButtons;


        for (int i = 0; i < numOfButtons; i++) {

            buttonList[i].setFont(NULL);
            buttonList[i].setFontFill(sf::Color::White);
            buttonList[i].setText(itemList[i]);
            buttonList[i].setTexture(NULL);

            switch (mType) {
                case menuType::DropDown:
                    buttonList[i].setPos(centerX, centerY);
                    break;
                case menuType::Horizontal:
                    spacing = buttonList[i].getSpriteHeight() * 2;
                    buttonList[i].setPos(centerX + (i * spacing), centerY - buttonList[i].getSpriteWidth() / 2);
                    break;
                case menuType::Vertical:
                    spacing = buttonList[i].getSpriteHeight() * 0.65f;
                    buttonList[i].setPos(centerX - buttonList[i].getSpriteWidth() / 2, centerY * 0.75f + (i * spacing));
                    break;
                case menuType::LevelSelect:
                    buttonList[i].setPos(centerX, centerY);
                    break;
                default:
                    buttonList[i].setPos(centerX, centerY);
                    break;
            }


            buttonList[i].setSize(0.5f, 0.5f);
        }

        buttonList[0].setFontFill(sf::Color::Blue);

        selectedItemIndex = 0;

    }

    void setMenuType(int typeNum) {
        mType = typeNum;
    }

    //navigation
    void moveUp() {
        if (selectedItemIndex - 1 >= 0) {
            buttonList[selectedItemIndex].setFontFill(sf::Color::White);
            selectedItemIndex--;
            buttonList[selectedItemIndex].setFontFill(sf::Color::Blue);
        }
    }

    void moveDown() {
        if (selectedItemIndex + 1 < items) {

            buttonList[selectedItemIndex].setFontFill(sf::Color::White);
            selectedItemIndex++;
            buttonList[selectedItemIndex].setFontFill(sf::Color::Blue);
        }
    }

    void moveLeft() {
        if (selectedItemIndex - 1 >= 0) {
            buttonList[selectedItemIndex].setFontFill(sf::Color::White);
            selectedItemIndex -= items / 2;
            buttonList[selectedItemIndex].setFontFill(sf::Color::Blue);

        }
    }

    void moveRight() {
        if (selectedItemIndex + 1 < items) {
            buttonList[selectedItemIndex].setFontFill(sf::Color::White);
            selectedItemIndex += (items / 2);
            buttonList[selectedItemIndex].setFontFill(sf::Color::Blue);
        }
    }

    int getPressedItem() { return selectedItemIndex; }

    sf::FloatRect getButtonBB(int buttonNum) {
        return buttonList[buttonNum].getBoundingBox();
    }

    void clearMen() {
        for (int i = 0; i < items; i++) {
            buttonList.pop_back();
        }
    }

    void draw(sf::RenderWindow &window) {
        for (int i = 0; i < items; i++) {
            window.draw(buttonList[i]);
        }
    }

private:
    int selectedItemIndex;
    int width;
    int height;
    int items;
    float spacing = 30.f;
    int mType;

    sf::Font font;
    std::vector<button> buttonList;
    std::vector<std::string> itemList;

};

#endif // MENU_H
