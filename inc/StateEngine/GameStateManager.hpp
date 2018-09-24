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

//custom headers
#include "../prefix.hpp"
#include "GameState.hpp"

namespace fin {
    class GameStateManager{

        public:
            void		init();
            void		cleanUp(GameState* state);

            void		changeState(GameState* state);
            void		pushState(GameState* state);
            void		popState();

            void		handleEvents(GameStateManager* manager);
            void		update();
            void		draw();
            void		sleep();

            //Functions for Drawwin control
            void		winClose();

        private:

            sf::Image			icon;
            sf::RenderWindow	drawWin;
            sf::VideoMode		desktop;
            int					screenWidth;
            int					screenHeight;
            int					BPP;
            bool				fullscreen;
            bool				running		= true;


    };

}
#endif // GAMESTATEMANAGER_H
