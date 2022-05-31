#ifndef STATE_H
#define STATE_H
#include "../window.h"

class State
{
protected:
    Window *m_window;
    sf::View m_view;
    std::list<sf::Drawable*> m_renderList;
public:
    virtual void active() = 0;
    virtual void update() = 0;
    virtual void draw()
    {
        for(auto it : m_renderList)
        {
            m_window->draw(*it);
        }
    }
    std::list<sf::Drawable*>& getRenderList()
    {
        return m_renderList;
    }
    Window* getWindow()
    {
        return m_window;
    }
    sf::View* getView()
    {
        return &m_view;
    }
    void setWindow(Window* l_window)
    {
        m_window = l_window;
    }
    void resize(sf::Vector2f &l_size)
    {
        m_view.setSize(l_size);
    }
    void resize(int l_x, int l_y)
    {
        m_view.setSize(l_x, l_y);
    }
};


#endif // STATE_H
