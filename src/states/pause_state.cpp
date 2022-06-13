#include "pause_state.h"

PauseState::PauseState()
{
    m_eventManager = EventManager::getEventManager();
    m_stateManager = StateManager::getStateManager();
    m_assetManager = AssetManager::getAssetManager();

    m_text.setFont(m_assetManager->getFont("FreeMono.otf"));
    m_text.setColor(sf::Color::Red);
    m_text.setString("Game Paused");
    m_renderList.push_back(&m_text);
}

PauseState::~PauseState(){}

void PauseState::active()
{
    m_eventManager->addCallback("pause", &PauseState::tooglePause, this);
}

void PauseState::update()
{
    m_text.setPosition(m_window->widht()/2-100, m_window->height()/2);
    m_view.setCenter(m_text.getPosition().x+100, m_text.getPosition().y);
    m_window->getSFMLWindow()->setView(m_view);
}

void PauseState::deactivate()
{
    m_eventManager->removeCallback("pause");
}

void PauseState::tooglePause(EventDetails*)
{
    m_stateManager->activeState("game");
}
