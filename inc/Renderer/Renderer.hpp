#ifndef DRAWWIN_H
#define DRAWWIN_H

#define S_WIDTH 1080
#define S_HEIGHT 720

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Renderer{
public:
    Renderer() {
        renderWin = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight, 32), "s", sf::Style::Default);
        event = sf::Event();
    }

    ~Renderer() = default;

    void init() {
        //renderWin->create(sf::VideoMode(screenWidth, screenHeight, 32), "s", sf::Style::Default);
        renderWin->setFramerateLimit(60);
        renderWin->setPosition(sf::Vector2i(0, 0));
        renderWin->setMouseCursorVisible(false);

        desktop = sf::VideoMode::getDesktopMode();
        screenHeight = desktop.height;
        screenWidth = desktop.width;
        BPP = desktop.bitsPerPixel;


        //sf::Mouse::setPosition(sf::Vector2i(0, 0), renderWin);
    }

    void clear() {
        renderWin->clear(sf::Color::Black);
    }

    void display() {
        renderWin->display();
    }

    void pollEvents() {
        while (renderWin->pollEvent(event)) {
            // check the type of the event...
            switch (event.type) {
                // window closed
                case sf::Event::Closed:
                    renderWin->close();
                    break;
                case sf::Event::KeyPressed:
                    break;
                default:
                    break;
            }
        }
    }

    void draw(sf::Drawable &myDraw){
        renderWin->draw(myDraw);
    }

    bool isOpen(){
        return renderWin->isOpen();
    }

    void closeWindow() {}

    void setFullscreen(bool toggle) {}

    void setResolution(int winHeight, int winWidth) {}

    void setIcon(std::string iconPath) {}

    void setVideoMode(sf::VideoMode modeChosen) {}


private:
    sf::RenderWindow *renderWin;
    sf::VideoMode desktop;
    sf::Event event;

    int BPP;
    int screenHeight = S_HEIGHT;
    int screenWidth = S_WIDTH;

    bool fullscreen;

};


#endif // !DRAWWIN_H
