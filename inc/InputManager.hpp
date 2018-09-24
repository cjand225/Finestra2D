#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <map>
#include <vector>

#include <SFML/Graphics.hpp>

class InputManager{

    public:
        InputManager() { };
        ~InputManager() { };

        void init();
        void update();

        //checks keyboard input
        bool keyPressed();
        bool keyReleased();

        //checks mouse input
        bool isHovering(sf::FloatRect currRect, sf::RenderWindow &window);
        bool isClicked(sf::FloatRect currRect, sf::Mouse::Button currButton, sf::RenderWindow &window);
        sf::Vector2i getMousePosition(sf::RenderWindow &window);

        //checks joystick input

    private:
        sf::Event event;



};



#endif // INPUTMANAGER_H
