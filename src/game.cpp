#include "game.h"

GameLoop::GameLoop() : m_window()
{
    m_eventManager = EventManager::getEventManager();
    m_stateManager = StateManager::getStateManager();
    m_clock.restart();
    m_elapsedTime = sf::Time::Zero;
    m_deltaTime = sf::Time::Zero;

    m_stateManager->addState("intro", new IntroState());
    m_stateManager->setStateWindow("intro", &m_window);
    m_stateManager->addState("game", new GameState());
    m_stateManager->setStateWindow("game", &m_window);
    m_stateManager->addState("pause", new PauseState());
    m_stateManager->setStateWindow("pause", &m_window);
    m_stateManager->addState("main_menu", new MainMenuState());
    m_stateManager->setStateWindow("main_menu", &m_window);
    m_stateManager->activeState("intro");

    m_eventManager->addCallback("resize", &GameLoop::resize, this);
}

GameLoop::~GameLoop(){}

Window* GameLoop::getWindow()
{
    return &m_window;
}

void GameLoop::handleInput()
{

}

void GameLoop::update()
{
    m_window.update();
    m_elapsedTime += m_clock.getElapsedTime();
    m_deltaTime = m_clock.restart();
    m_stateManager->update();
}

void GameLoop::render()
{
    m_window.beginDraw();

    for(auto it : m_renderPoll)
    {
        m_window.draw(*it.second);
    }

    //update all
    m_stateManager->draw();

    m_window.endDraw();
}

void GameLoop::addItem(std::string l_name, sf::Drawable *l_item)
{
    if(m_renderPoll.find(l_name) != m_renderPoll.end())
        ;//Todo error
    else
        m_renderPoll[l_name] = l_item;
}

void GameLoop::tooglePause(EventDetails*)
{
    if(m_stateManager->checkCurrentState() == "pause")
    {
        m_stateManager->activeState("game");
    }
    else
    {
        m_stateManager->activeState("pause");
    }
}

void GameLoop::resize(EventDetails *l_details)
{
    m_window.resize(l_details);
    m_stateManager->getCurrentState()->resize(l_details->m_size.x, l_details->m_size.y);
}
