#ifndef GUI_H
#define GUI_H
#include <SFML/Graphics.hpp>
#include <functional>
#include "../window.h"
#include "../assetmanager.h"

class GUI : public sf::Drawable
{
protected:
    AssetManager *m_assetManager;
    int m_x;
    int m_y;
    std::function<void()> m_callback;
public:
    GUI();
    int getX();
    int getY();
    virtual void clicked(EventDetails*) = 0;
    virtual void draw(Window *window) = 0;
    template<class T>
    void setAction(void(T::*l_func)(), T* l_instance)
    {
        auto tmp = std::bind(l_func, l_instance);
        m_callback = tmp;
    }
};

#endif // GUI_H
