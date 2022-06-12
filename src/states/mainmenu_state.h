#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H
#include<iostream>
#include<SFML/Graphics.hpp>
#include"state.h"
#include"../gui/textbox.h"
#include"../assetmanager.h"

class MainMenuState : public State
{
private:
    AssetManager *m_assetManager;
    TextBox *m_textbox;
public:
    MainMenuState();
    ~MainMenuState();
    virtual void active() override;
    virtual void update() override;
    void stub(){std::cout<<"suk"<<std::endl;}
};

#endif // MAINMENUSTATE_H
