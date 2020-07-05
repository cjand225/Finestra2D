#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

//State Manager file refs
#include <StateEngine/GameStateManager.hpp>

#include <Renderer/Renderer.hpp>
#include <InputManager.hpp>

class Renderer;

class GameStateManager;

class Engine {

public:
    Engine() {
    }

    void init() {
        gManager->init();
        gRender->init();
        gInput->init();

    }

    void runLoop() {

        tClock.restart();
        while (gRender->isOpen()) {
            currentTime = tClock.getElapsedTime();
            tElapsed += currentTime - previousTime;
            previousTime = currentTime;
            tDelay += tElapsed;

            gRender->pollEvents();

            while (tDelay > frameTime) {
                gInput->update();
                tDelay -= frameTime;
            }
            gRender->clear();
            sf::CircleShape shape(50.f);
            shape.setFillColor(sf::Color(100, 250, 50));
            gRender->draw(shape);
            gRender->display();
        }
    }


protected:

private:
    GameStateManager* gManager = new GameStateManager();
    Renderer* gRender = new Renderer();
    InputManager* gInput = new InputManager();

    bool engineRunning;

    //Timing
    sf::Clock tClock = sf::Clock();
    sf::Time currentTime;
    sf::Time previousTime;
    sf::Time tDelay;
    sf::Time tElapsed;
    sf::Time frameTime = sf::seconds(1.f / 60.f);
    float tFrameRate = 0.0f;
    sf::Time tsleep = sf::Time::Zero;


};


#endif // ENGINE_H
