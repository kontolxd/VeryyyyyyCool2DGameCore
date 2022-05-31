#pragma once
#include "state.h"
#include <SFML/Graphics.hpp>
#include <list>
#include "../eventmanager.h"
#include "../states/statemanager.h"
class GameState : public State
{
private:
    EventManager *m_eventManager;
    StateManager *m_stateManager;
    sf::CircleShape *shape;
    float l_x, l_y;
    void tooglePause(EventDetails*);
public:
    GameState();
    virtual void active();
    virtual void update();
};
