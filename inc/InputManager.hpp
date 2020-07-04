#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <map>
#include <vector>

#include <SFML/Graphics.hpp>

class InputManager {

public:
    InputManager() = default;;

    ~InputManager() = default;;

    void init() {}

    void update() {}

    //checks keyboard input
    bool keyPressed() { return false; }

    bool keyReleased() { return false; }

    //checks mouse input
    bool isHovering(sf::FloatRect currRect, sf::RenderWindow &window) {
        sf::IntRect tempRect = (sf::IntRect) currRect;
        return tempRect.contains(sf::Mouse::getPosition(window));

    }

    bool isClicked(sf::FloatRect currRect, sf::Mouse::Button currButton, sf::RenderWindow &window) {
        if (sf::Mouse::isButtonPressed(currButton)) {
            sf::IntRect tempRect = (sf::IntRect) currRect;

            if (tempRect.contains(sf::Mouse::getPosition(window))) {
                return true;
            }
        }
        return false;
    }

    sf::Vector2i getMousePosition(sf::RenderWindow &window) { return sf::Mouse::getPosition(window); }

    //checks joystick input

private:
    sf::Event event{};


};


#endif // INPUTMANAGER_H
