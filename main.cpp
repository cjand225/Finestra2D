
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <Engine.hpp>

int main() {

    Engine gEngine;
    //sf::sleep(sf::Time().Zero);
    gEngine.init();
    gEngine.runLoop();

    return 0;
}

