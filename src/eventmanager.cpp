#include"eventmanager.h"
EventManager *EventManager::sInstance = nullptr;
enum class EventType
{
    Closed = sf::Event::Closed,
    Resized = sf::Event::Resized,
    LostFocus = sf::Event::LostFocus,
    GainedFocus = sf::Event::GainedFocus,
    TextEntered = sf::Event::TextEntered,
    KeyPressed = sf::Event::KeyPressed,
    KeyReleased = sf::Event::KeyReleased,
    MWheelScroled = sf::Event::MouseWheelScrolled,
    MButtonPressed = sf::Event::MouseButtonPressed,
    MButtonReleased = sf::Event::MouseButtonReleased,
    MouseMoved = sf::Event::MouseMoved,
    MouseEntered = sf::Event::MouseEntered,
    MouseLeft = sf::Event::MouseLeft,
    MneLenDelatJoystick = sf::Event::Count + 1
};

struct EventInfo
{
    int m_code;
    EventInfo(int l_code = -1) : m_code(l_code){}
};

struct Binding
{
    EventDetails m_details;
    std::string m_name;
    EventType m_type;
    EventInfo m_info;
};

EventManager::EventManager()
{
    if(sInstance == nullptr)
    {
        loadBindings("keys.cfg");
        sInstance = this;
    }

}

EventManager* EventManager::getEventManager()
{
    EventManager *kostyl = new EventManager();
    //нет, sInstance'у нельзя присвоить то что выше
    return sInstance;
}

EventManager::~EventManager()
{
    for(auto &it : m_bindings)
    {
        removeBinding(it.first);
    }
}

bool EventManager::addBinding(std::string l_name, Binding* l_binding)
{
    return m_bindings.emplace(l_name, l_binding).second;
}

void EventManager::removeBinding(std::string l_name)
{
    delete m_bindings[l_name];
    m_bindings.erase(l_name);
}

void EventManager::removeCallback(std::string l_name)
{
    m_callbacks.erase(l_name);
}

void EventManager::handleEvent(sf::Event &l_event)
{
    EventType sfmlEvent = (EventType)l_event.type;
    for(auto &it : m_bindings)
    {
        Binding *bind = it.second;
        if(it.second->m_type == sfmlEvent)
        {
            switch(sfmlEvent)
            {
            case EventType::Resized:
                bind->m_details.m_size.x = l_event.size.width;
                bind->m_details.m_size.y = l_event.size.height;
                break;
            case EventType::TextEntered:
                bind->m_details.m_text = l_event.text.unicode;
                break;
            case EventType::KeyPressed:
            case EventType::KeyReleased:
                bind->m_details.m_keyCode = l_event.key.code;
                break;
            case EventType::MWheelScroled:
                bind->m_details.m_deltaScroll = l_event.mouseWheelScroll.delta;
                break;
            case EventType::MButtonPressed:
            case EventType::MButtonReleased:
                bind->m_details.m_position.x = l_event.mouseButton.x;
                bind->m_details.m_position.y = l_event.mouseButton.y;
                break;
            case EventType::MouseMoved:
                bind->m_details.m_position.x = l_event.mouseMove.x;
                bind->m_details.m_position.y = l_event.mouseMove.y;
                break;
            default:
                break;
            }
        }
        std::string bindName = it.first;
        auto callback_it = m_callbacks.find(bindName);
        if(callback_it != m_callbacks.end())
        {
            if(bind->m_type == sfmlEvent && bind->m_info.m_code == bind->m_details.m_keyCode)
            {
                callback_it->second(&bind->m_details);
            }
        }
    }
}

void EventManager::loadBindings(std::string l_filename)
{
    std::string callbackName;
    std::string keyCode;
    std::string eventCode;

    std::ifstream stream;
    stream.open(l_filename);
    if(!stream.is_open())
    {
        //TODO Error
        std::cout<<"Error to open file: "<<l_filename<<std::endl;
    }
    std::string line;
    while(getline(stream, line))
    {
        if(line[0] == '#') continue;
        Binding *bind = new Binding;
        {
            std::string delimiter = ":";
            int pos = 0;
            int length = 0;
            length = line.find(delimiter, pos) - pos;
            callbackName = line.substr(pos, length);
            pos += length+1;
            length = line.find(delimiter, pos) - pos;
            keyCode = line.substr(pos, length);
            pos += length+1;
            length = line.find(delimiter, pos) - pos;
            eventCode = line.substr(pos, length);
        }
        try
        {
            bind->m_type = (EventType)stoi(eventCode);
        }
        catch (...)
        {
            //TODO error
        }
        try
        {
            bind->m_info.m_code = stoi(keyCode);
        }
        catch (...)
        {
            //TODO error
        }
        addBinding(callbackName, bind);

    }
}
