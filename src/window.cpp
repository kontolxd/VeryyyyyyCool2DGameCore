#include "window.h"

Window::Window()
{
    m_eventManager = EventManager::getEventManager();
    setup(1920, 1080, "Title", false);
    create();
}

Window::Window(sf::Uint16 l_width, sf::Uint16 l_height, std::string l_title, bool l_isFullscreen)
{
    setup(l_width, l_height, l_title, l_isFullscreen);
    create();
}

Window::~Window(){}

void Window::create()
{
    auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create(sf::VideoMode(m_width, m_height), m_title, style);
}

void Window::setup(sf::Uint16 l_width, sf::Uint16 l_height, std::string l_title, bool l_isFullscreen)
{
    m_width = l_width;
    m_height = l_height;
    m_title = l_title;
    m_isFullscreen = l_isFullscreen;
    m_isDone = false;
    m_eventManager->addCallback("toogle_fullscreen", &Window::toogleFullscreen, this);
    m_eventManager->addCallback("close", &Window::close, this);
}

void Window::destroy()
{
    m_window.close();
}

void Window::close(EventDetails*)
{
    destroy();
    m_isDone = true;
}

void Window::toogleFullscreen(EventDetails*)
{
    m_isFullscreen = !m_isFullscreen;
    destroy();
    create();
}

void Window::draw(sf::Drawable &l_drawable)
{

    m_window.draw(l_drawable);
}

void Window::update()
{
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        m_eventManager->handleEvent(event);
    }
}

void Window::beginDraw()
{
    m_window.clear(sf::Color::Black);
}

void Window::endDraw()
{
    m_window.display();
}

bool Window::isDone()
{
    return m_isDone;
}

int Window::widht()
{
    return m_width;
}

int Window::height()
{
    return m_height;
}

sf::RenderWindow* Window::getSFMLWindow()
{
    return &m_window;
}

void Window::resize(EventDetails *l_details)
{
    m_window.setSize(l_details->m_size);
    m_width = l_details->m_size.x;
    m_height = l_details->m_size.y;
}
