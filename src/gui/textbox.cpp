#include "textbox.h"

TextBox::TextBox()
{
    m_callback = [](){};
    m_rect.setPosition(m_x, m_y);
    m_text.setPosition(m_x, m_y + (m_height/2)*(m_height/4));
}

void TextBox::clicked()
{
    m_callback();
}

void TextBox::setAction(std::function<void ()> l_action)
{
    m_callback = l_action;
}

void TextBox::setColor(sf::Color l_color)
{
    m_color = l_color;
    m_rect.setFillColor(m_color);
}

void TextBox::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    m_color.r = r;
    m_color.g = g;
    m_color.b = b;
    m_color.a = a;
    m_rect.setFillColor(m_color);
}

void TextBox::setSize(int l_width, int l_height)
{
    m_rect.setSize(sf::Vector2f(l_width, l_height));
    m_width = l_width;
    m_height = l_height;
    m_text.setPosition(m_x, m_y + (m_height/2)-m_text.getCharacterSize()/2);
}

void TextBox::setFont(std::string l_fontName)
{
    m_font = m_assetManager->getFont(l_fontName);
    m_text.setFont(m_font);
}

void TextBox::setText(std::string l_content)
{
    m_text.setString(l_content);
}

void TextBox::draw(Window *l_window)
{
    l_window->draw(m_rect);
    l_window->draw(m_text);
}
