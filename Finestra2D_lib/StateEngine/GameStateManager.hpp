#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

//Standard
#include <vector>
#include <string>

//SFML specific
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Engine.hpp>


class GameState;

class Engine;

class GameStateManager {

public:
    GameStateManager(){
        screenHeight = 1080;
        screenWidth = 1920;
        fullscreen = false;
        BPP = 10;
    };

    ~GameStateManager() = default;


    void init() {}

    void cleanUp(GameState *state) {}

    void changeState(GameState *state) {}

    void pushState(GameState *state) {}

    void popState() {}

    void handleEvents(GameStateManager *manager) {}

    void update() {}

    void draw() {}

    void sleep() {}

    //Functions for renderWin control
    void winClose() {}

private:

    sf::Image icon;
    sf::RenderWindow drawWin;
    sf::VideoMode desktop;
    int screenWidth;
    int screenHeight;
    int BPP;
    bool fullscreen;
    bool running = true;


};


class GameState {

public:
    virtual void Init() = 0;

    virtual void Cleanup() = 0;

    virtual void Pause() = 0;

    virtual void Resume() = 0;

    virtual void HandleEvents(Engine *game) = 0;

    virtual void Update(Engine *game) = 0;

    virtual void Draw(Engine *game) = 0;

    virtual void ChangeState(GameStateManager *manager, GameState *state) {
        manager->changeState(state);
    }


protected:


private:

};


#endif // GAMESTATEMANAGER_H
