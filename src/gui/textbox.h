#ifndef TEXTBOX_H
#define TEXTBOX_H
#include "gui.h"
#include <SFML/Graphics.hpp>
#include <stdint.h>
#include "../eventmanager.h"
class TextBox : public GUI
{
private:
    EventManager *m_eventManager;
    int m_width, m_height;
    sf::Color m_color;
    sf::RectangleShape *m_rect;
    sf::Text m_text;
    sf::Font m_font;
    virtual void draw(sf::RenderTarget &l_target, sf::RenderStates states) const override;
public:
    TextBox();
    ~TextBox();
    void setColor(sf::Color color);
    void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
    void setSize(int width, int height);
    void setText(std::string content);
    void setFont(std::string fontName);
    void setPosition(uint8_t x, uint8_t y);
    virtual void clicked(EventDetails*) override;
    virtual void draw(Window *window) override;

};

#endif
