#ifndef INTRO_STATE_H
#define INTRO_STATE_H
#include"state.h"
#include<SFML/Graphics.hpp>
#include"../assetmanager.h"
#include"../states/statemanager.h"
#include<iostream>
class IntroState : public State
{
private:
    float m_a;
    sf::Clock m_clock;
    sf::Time m_elapsedTime;
    int m_deltaTime;
    AssetManager *m_assetManager;
    StateManager *m_stateManager;
    sf::Text m_SlavesProduction;
    sf::Text m_VeryVeryVeryImportantVariable;
public:
    IntroState();
    virtual void active() override;
    virtual void update() override;
};

#endif // INTRO_STATE_H
