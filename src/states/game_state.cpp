#include "game_state.h"

GameState::GameState() : l_x(0), l_y(0)
{
    m_eventManager = EventManager::getEventManager();
    m_stateManager = StateManager::getStateManager();
//    shape = new sf::CircleShape(50);
//    shape->setFillColor(sf::Color::Red);
//    m_renderList.push_back(shape);
}

GameState::~GameState(){}

void GameState::active()
{
    m_eventManager->addCallback("pause", &GameState::tooglePause, this);
    m_window->getSFMLWindow()->setView(m_view);
}

void GameState::update()
{
    //m_view.setCenter(shape->getPosition());
    m_window->getSFMLWindow()->setView(m_view);
}

void GameState::tooglePause(EventDetails *)
{
    m_stateManager->activeState("pause");
}
