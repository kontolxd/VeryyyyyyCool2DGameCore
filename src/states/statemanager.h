#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include<unordered_map>
#include<iostream>
#include"state.h"
using States = std::unordered_map<std::string, State*>;

class StateManager
{
private:
    static StateManager *sInstance;
    StateManager();
    States m_states;
    State *m_currentState;
    std::string m_currentStateName;
public:
    static StateManager* getStateManager();
    void activeState(std::string);
    void update();
    void addState(std::string, State*);
    void setStateWindow(std::string, Window*);
    void draw();
    std::string checkCurrentState();
    State *getCurrentState();
};

#endif // STATEMANAGER_H
