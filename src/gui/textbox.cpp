#include "textbox.h"

TextBox::TextBox()
{
    m_eventManager = EventManager::getEventManager();
    m_eventManager->addCallback("clicked", &TextBox::clicked, this);

    m_rect = new sf::RectangleShape();

    m_callback = [](){};
//    m_rect.setPosition(m_x, m_y);
//    m_text.setPosition(m_x, m_y + (m_height/2)*(m_height/4));
}

TextBox::~TextBox()
{
    delete m_rect;
}

void TextBox::clicked(EventDetails* l_details)
{

    int x = l_details->m_position.x;
    int y = l_details->m_position.y;
    std::cout<<x<<" "<<y<<std::endl<<m_x<<" "<<m_y<<std::endl<<m_rect->getPosition().x<<"-------"<<std::endl;
    if(x > m_x && y > m_y && x < m_x+m_width && y < m_y+m_height)
    {
        m_callback();
    }
}

void TextBox::setColor(sf::Color l_color)
{
    m_color = l_color;
    m_rect->setFillColor(m_color);
}

void TextBox::setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    m_color.r = r;
    m_color.g = g;
    m_color.b = b;
    m_color.a = a;
    m_rect->setFillColor(m_color);
}

void TextBox::setSize(int l_width, int l_height)
{
    m_rect->setSize(sf::Vector2f(l_width, l_height));
    m_width = l_width;
    m_height = l_height;
    //m_text.setPosition(m_x, m_y + (m_height/2)-m_text.getCharacterSize()/2);
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
    l_window->draw(*m_rect);
    l_window->draw(m_text);
}

void TextBox::draw(sf::RenderTarget &l_target, sf::RenderStates states) const
{
    l_target.draw(*m_rect, states);
    l_target.draw(m_text, states);
}

void TextBox::setPosition(uint8_t l_x, uint8_t l_y)
{
    m_x = l_x;
    m_y = l_y;
    m_rect->setPosition(m_x, m_y);
    m_text.setPosition(m_x, m_y);
}

