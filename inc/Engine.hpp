#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/System.hpp>


//State Manager file refs
#include "./StateEngine/GameStateManager.hpp"
#include "./StateEngine/PlayState.hpp"
#include "./StateEngine/PauseState.hpp"
#include "./StateEngine/IntroState.hpp"
#include "./StateEngine/LevelSelectState.hpp"

//Renderer file refs
//#include "../Renderer/Renderer.hpp"

#include "Renderer/Renderer.hpp"

//Asset file refs

//input file refs
#include "InputManager.hpp"


namespace fin{
    class Engine;

    class Engine{

        public:
            Engine() { };

            void init();
            void runLoop();
            bool isRunning();
            void quit();

        protected:

        private:
            GameStateManager gManager;
            Renderer gRender;
            InputManager gInput;

            bool engineRunning;

            //Timing
            sf::Clock   tClock;
            sf::Time    currentTime;
            sf::Time    previousTime;
            sf::Time    tDelay;
            sf::Time    tElapsed;
            sf::Time    frameTime = sf::seconds(1.f / 60.f);
            float		tFrameRate = 0.0f;
            sf::Time    tsleep = sf::Time::Zero;


    };

}



#endif // ENGINE_H
