#ifndef DRAWWIN_H
#define DRAWWIN_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Renderer {
public:
    Renderer() = default;

    ~Renderer() = default;

    void init() {
        renderWin.create(sf::VideoMode(screenWidth, screenHeight, 32), "s", sf::Style::Default);
        renderWin.setFramerateLimit(60);
        renderWin.setPosition(sf::Vector2i(0, 0));
        renderWin.setMouseCursorVisible(false);

        desktop = sf::VideoMode::getDesktopMode();
        screenHeight = desktop.height;
        screenWidth = desktop.width;
        BPP = desktop.bitsPerPixel;


        sf::Mouse::setPosition(sf::Vector2i(0, 0), renderWin);
    }

    void draw() {}

    void clearWindow() {}

    void closeWindow() {}

    void setFullscreen(bool toggle) {}

    void setResolution(int winHeight, int winWidth) {}

    void setIcon(std::string iconPath) {}

    void setVideoMode(sf::VideoMode modeChosen) {}


private:
    sf::RenderWindow renderWin;
    sf::VideoMode desktop;

    int BPP;
    int screenHeight;
    int screenWidth;

    bool fullscreen;
    bool winRunning;

};


#endif // !DRAWWIN_H
