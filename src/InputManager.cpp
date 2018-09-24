#include "../inc/InputManager.hpp"


bool InputManager::isClicked(sf::FloatRect currRect, sf::Mouse::Button button, sf::RenderWindow &window){

    if(sf::Mouse::isButtonPressed(button)){
        sf::IntRect tempRect = (sf::IntRect)currRect;

        if(tempRect.contains(sf::Mouse::getPosition(window))){
            return true;
        }
    }
    return false;
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow &window){

    return sf::Mouse::getPosition(window);
}

bool InputManager::isHovering(sf::FloatRect currRect, sf::RenderWindow &window){

    sf::IntRect tempRect = (sf::IntRect)currRect;

    if(tempRect.contains(sf::Mouse::getPosition(window))){
        return true;
    }

    return false;
}
