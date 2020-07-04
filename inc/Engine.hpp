#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/System.hpp>


//State Manager file refs
#include <StateEngine/GameStateManager.hpp>
#include <StateEngine/PlayState.hpp>
#include <StateEngine/PauseState.hpp>
#include <StateEngine/IntroState.hpp>
#include <StateEngine/LevelSelectState.hpp>
#include <Renderer/Renderer.hpp>
#include <InputManager.hpp>

class Renderer;

class Engine {

public:
    Engine() {
        //gManager = new GameStateManager();
    }

    void init() {

        //gManager.init();
        //gRender.init();
    }

    void runLoop() {

        tClock.restart();
        while (isRunning()) {
            currentTime = tClock.getElapsedTime();
            tElapsed += currentTime - previousTime;
            previousTime = currentTime;
            tDelay += tElapsed;
            //handleEvents(this);

            while (tDelay > frameTime) {
                //            update();
                tDelay -= frameTime;

            }
            // draw();
        }
    }

    bool isRunning() const {
        return engineRunning;
    }

    void quit() {
        engineRunning = false;
    }

protected:

private:
    GameStateManager gManager;
    Renderer gRender;
    InputManager gInput;

    bool engineRunning;

    //Timing
    sf::Clock tClock;
    sf::Time currentTime;
    sf::Time previousTime;
    sf::Time tDelay;
    sf::Time tElapsed;
    sf::Time frameTime = sf::seconds(1.f / 60.f);
    float tFrameRate = 0.0f;
    sf::Time tsleep = sf::Time::Zero;


};


#endif // ENGINE_H
