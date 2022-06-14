#ifndef WINDOW_H
#define WINDOW_H
#include<iostream>
#include<list>
#include<SFML/Graphics.hpp>
#include"eventmanager.h"
class Window
{
private:
//    StateManager *m_stateManager;
    EventManager *m_eventManager;
    sf::RenderWindow m_window;
    std::string m_title;
    sf::Uint16 m_width;
    sf::Uint16 m_height;
    bool m_isFullscreen;
    bool m_isDone;
    void setup(sf::Uint16 l_width, sf::Uint16 l_height, std::string l_title, bool l_isFullscreen);
    void create();
    void destroy();
public:
    Window();
    Window(sf::Uint16 l_width, sf::Uint16 l_height, std::string l_title, bool l_isFulscreen);
    ~Window();
    void close(EventDetails*);
    void toogleFullscreen(EventDetails*);
    void resize(EventDetails*);
    void draw(sf::Drawable &l_drawable);
    void update();
    void beginDraw();
    void endDraw();
    bool isDone();
    int widht();
    int height();
    sf::RenderWindow* getSFMLWindow();
};

#endif // WINDOW_H
