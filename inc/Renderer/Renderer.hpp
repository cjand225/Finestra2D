#pragma once
#ifndef DRAWWIN_H
#define DRAWWIN_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
namespace fin{

    class Renderer {
        public:
            Renderer() { };
            ~Renderer() { };

            void init();

            void draw();
            void clearWindow();
            void closeWindow();

            void setFullscreen(bool toggle);
            void setResolution(int winHeight, int winWidth);
            void setIcon(std::string iconPath);

            void setVideoMode(sf::VideoMode modeChosen);


        private:
            sf::RenderWindow renderWin;
            sf::VideoMode desktop;

            int BPP;
            int screenHeight;
            int screenWidth;

            bool fullscreen;
            bool winRunning;

    };

}

#endif // !DRAWWIN_H
