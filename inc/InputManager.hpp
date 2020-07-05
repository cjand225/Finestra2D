#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <map>
#include <vector>

#include <SFML/Graphics.hpp>

class InputManager {

public:
    InputManager() = default;

    ~InputManager() = default;;

    void init() {
    }

    void update() {}

    //checks mouse input
    static bool isHovering(sf::FloatRect currRect, sf::RenderWindow &window) {
        return currRect.contains((sf::Vector2f) sf::Mouse::getPosition(window));
    }

    static bool isClicked(sf::FloatRect currRect, sf::Mouse::Button currButton, sf::RenderWindow &window) {
        return sf::Mouse::isButtonPressed(currButton) &&
               currRect.contains((sf::Vector2f) sf::Mouse::getPosition(window));
    }

    static sf::Vector2i getMousePosition(sf::RenderWindow &window) { return sf::Mouse::getPosition(window); }


private:

};


#endif // INPUTMANAGER_H
