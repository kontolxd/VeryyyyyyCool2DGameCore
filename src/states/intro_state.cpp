#include "intro_state.h"

IntroState::IntroState()
{
    m_elapsedTime = sf::Time::Zero;
    m_deltaTime = 0;
    m_a = 0;
    m_eventManager = EventManager::getEventManager();
    m_assetManager = AssetManager::getAssetManager();
    m_stateManager = StateManager::getStateManager();
    m_SlavesProduction.setFont(m_assetManager->getFont("FreeMono.otf"));
    m_SlavesProduction.setFillColor(sf::Color(255, 174, 66, m_a));
    m_SlavesProduction.setString("Slaves Production Present");
    m_VeryVeryVeryImportantVariable.setFont(m_assetManager->getFont("FreeMono.otf"));
    m_VeryVeryVeryImportantVariable.setFillColor(sf::Color(255,0,0,m_a));
    m_VeryVeryVeryImportantVariable.setString("Very Very Cool Game");
    m_renderList.push_back(&m_SlavesProduction);
    m_renderList.push_back(&m_VeryVeryVeryImportantVariable);

    m_eventManager->addCallback("skip_intro", &IntroState::skip, this);
}

IntroState::~IntroState()
{

}

void IntroState::active()
{

}

void IntroState::update()
{
    m_view.setCenter(m_SlavesProduction.getPosition().x+200, m_SlavesProduction.getPosition().y);
    m_window->getSFMLWindow()->setView(m_view);

    m_elapsedTime += m_clock.getElapsedTime();
    m_deltaTime = m_clock.restart().asMicroseconds();
    m_SlavesProduction.setPosition(0, 0);
    m_VeryVeryVeryImportantVariable.setPosition(0, 0+50);
    m_SlavesProduction.setFillColor(sf::Color(255,174,66,m_a));
    m_VeryVeryVeryImportantVariable.setFillColor(sf::Color(255,0,0,m_a));
    if(m_a < 255)
        m_a = m_elapsedTime.asSeconds()*50;
    else
        m_stateManager->activeState("main_menu");
}

void IntroState::skip(EventDetails *)
{
    m_stateManager->activeState("main_menu");
}
