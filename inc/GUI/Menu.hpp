#ifndef MENU_H
#define MENU_H

#include "../prefix.hpp"

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Button.hpp"

enum menuType{

    LevelSelect,
    Vertical,
    DropDown,
    Horizontal

};

class menu
{
    public:
        menu();
        ~menu();

        //new updated version of menu
        void    	setMenuItems(std::vector<std::string> menuItems);
        void    	setMenuPos(sf::View currentView);
        void    	setMenuType(int mType);

        //navigation
        void		moveUp();
        void		moveDown();
        void		moveLeft();
        void		moveRight();
        int		getPressedItem() { return selectedItemIndex; }

        sf::FloatRect 	getButtonBB(int buttonNum);
        void 		clearMen();


        void		draw(sf::RenderWindow &window);

    private:
	int		selectedItemIndex;
	int		width;
	int		height;
	int		items;
        float		spacing = 30.f;
        int         	mType;

	sf::Font	font;
	std::vector<button> buttonList;
	std::vector<std::string> itemList;

};

#endif // MENU_H
