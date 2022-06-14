#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include<iostream>
#include<SFML/Graphics.hpp>
#include"state.h"
#include"../gui/textbox.h"
#include"../assetmanager.h"
#include"../eventmanager.h"
#include"statemanager.h"

class MainMenuState : public State
{
private:
    AssetManager *m_assetManager;
    StateManager *m_stateManager;
    EventManager *m_eventManager;
    TextBox *m_newButton;
    TextBox *m_settingsButton;
    TextBox *m_exitButton;
    void b_exit();
    void b_settings();
    void b_new();
    void clicked(EventDetails*);
public:
    MainMenuState();
    ~MainMenuState();
    virtual void active() override;
    virtual void update() override;
    virtual void deactivate() override;
};

#endif // MAINMENUSTATE_H
