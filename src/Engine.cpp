#include "../inc/Engine.hpp"

namespace fin {


    void Engine::init(){

        gManager.inIt();
        gRender.init();
    }

    void Engine::runLoop(){

        tClock.restart();

         while(isRunning())
        {
            currentTime = tClock.getElapsedTime();
            tElapsed += currentTime - previousTime;
            previousTime = currentTime;
            tDelay += tElapsed;
//          handleEvents(this);

            while (tDelay > frameTime)
            {
    //            update();
                tDelay -= frameTime;

            }

           // draw();
        }

    }

    bool Engine::isRunning(){
        return engineRunning;
    }

    void Engine::quit(){
        engineRunning = false;
        return;
    }

}
