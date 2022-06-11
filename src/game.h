#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <map>
#include "window.h"
#include "gui/textbox.h"
#include "eventmanager.h"
#include "states/statemanager.h"
#include "states/game_state.h"
#include "states/pause_state.h"
#include "states/intro_state.h"
#include "states/mainmenu_state.h"
class GameLoop
{
private:
    EventManager *m_eventManager;
    StateManager *m_stateManager;
    std::map<std::string, sf::Drawable*> m_renderPoll;
    Window m_window;
    sf::Clock m_clock;
    sf::Time m_elapsedTime;
    sf::Time m_deltaTime;
public:
    GameLoop();
    ~GameLoop();
    Window* getWindow();
    void handleInput();
    void update();
    void render();
    void addItem(std::string l_name, sf::Drawable *l_item);
    void tooglePause(EventDetails*);
    void resize(EventDetails*);
};

#endif // GAME_H
