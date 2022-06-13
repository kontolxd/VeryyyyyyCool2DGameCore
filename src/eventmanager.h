#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include<functional>
#include<unordered_map>
#include<iostream>
#include<fstream>
#include<SFML/Graphics.hpp>
enum class EventType;
struct EventDetails;
struct eventInfo;
struct Binding;

using Bindings = std::unordered_map<std::string, Binding*>;
using Callbacks = std::unordered_map<std::string, std::function<void(EventDetails*)>>;

class EventManager
{
private:
    static EventManager *sInstance;
    Bindings m_bindings;
    Callbacks m_callbacks;
    void loadBindings(std::string l_filename);
    EventManager();
public:
    static EventManager *getEventManager();
    ~EventManager();
    bool addBinding(std::string, Binding*);
    void removeBinding(std::string);
    void handleEvent(sf::Event&);
    void removeCallback(std::string);
    template<class T>
    bool addCallback(std::string l_name, void(T::*l_func)(EventDetails*), T *instance)
    {
        if(m_callbacks.find(l_name) != m_callbacks.end())
        {
            //memory leak???
            m_callbacks.erase(m_callbacks.find(l_name));
        }
        auto tmp = std::bind(l_func, instance, std::placeholders::_1);
        return m_callbacks.emplace(l_name, tmp).second;
    }

};

struct EventDetails
{
    sf::Vector2u m_size;      //resize
    sf::Vector2i m_position;  //mouse button press/release and mouse moved
    std::string m_text;       //text entered
    int m_deltaScroll;        //mouse wheel scroll
    int m_keyCode;
    EventDetails(){clear();}
    void clear()
    {
        m_size = sf::Vector2u(0,0);
        m_position = sf::Vector2i(0,0);
        m_text = "";
        m_deltaScroll = 0;
        m_keyCode = -1;
    }
};

#endif
