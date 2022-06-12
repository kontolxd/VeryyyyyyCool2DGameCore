#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H
#include "state.h"
#include<SFML/Graphics.hpp>
#include"../assetmanager.h"
#include"../states/statemanager.h"
#include"../eventmanager.h"
class PauseState : public State
{
private:
    sf::Text m_text;
    AssetManager *m_assetManager;
    StateManager *m_stateManager;
    EventManager *m_eventManager;
public:
    PauseState();
    ~PauseState();
    virtual void active();
    virtual void update();
    void tooglePause(EventDetails*);
};

#endif // PAUSE_STATE_H
