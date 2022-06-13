#include "statemanager.h"
StateManager *StateManager::sInstance = nullptr;

StateManager::StateManager()
{
    if(sInstance == nullptr)
        sInstance = this;
}

StateManager* StateManager::getStateManager()
{
    StateManager *kostyl = new StateManager();
    return sInstance;
}

void StateManager::activeState(std::string l_stateName)
{
    auto state = m_states.find(l_stateName);
    if(state != m_states.end())
    {
        if(m_currentStateName != "")
            m_currentState->deactivate();
        m_currentState = state->second;
        m_currentState->active();
        m_currentStateName = l_stateName;
    }
    else
    {
        //TODO error
    }
}

void StateManager::update()
{
    m_currentState->update();
}

void StateManager::addState(std::string l_name, State *l_state)
{
    if(m_states.find(l_name) == m_states.end())
    {
        m_states[l_name] = l_state;
    }
    else
    {
        //TODO ERROR
    }
}

void StateManager::setStateWindow(std::string l_name, Window *l_window)
{
    if(m_states.find(l_name) != m_states.end())
    {
        m_states[l_name]->setWindow(l_window);
        *m_states[l_name]->getView() = m_states[l_name]->getWindow()->getSFMLWindow()->getDefaultView();
    }
}

void StateManager::draw()
{
    m_currentState->draw();
}

std::string StateManager::checkCurrentState()
{
    return m_currentStateName;
}

State *StateManager::getCurrentState()
{
    return m_currentState;
}
