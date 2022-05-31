#ifndef GUI_H
#define GUI_H
#include <functional>
#include "../window.h"
#include "../assetmanager.h"
class GUI
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
    virtual void setAction(std::function<void()> action) = 0;
    virtual void clicked() = 0;
    virtual void draw(Window *window) = 0;
};

#endif // GUI_H
