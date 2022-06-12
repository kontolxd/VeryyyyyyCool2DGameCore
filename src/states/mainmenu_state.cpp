#include "mainmenu_state.h"

MainMenuState::MainMenuState()
{
    m_assetManager = AssetManager::getAssetManager();

    m_textbox = new TextBox();
    m_textbox->setColor(sf::Color::Red);
    m_textbox->setSize(100,100);
    m_textbox->setFont("FreeMono.otf");
    m_textbox->setText("Ya syka");
    m_textbox->setPosition(0,0);
    m_textbox->setAction(&MainMenuState::stub, this);
    m_renderList.push_back(m_textbox);

}

MainMenuState::~MainMenuState()
{
    delete m_textbox;
}

void MainMenuState::active()
{
    m_window->getSFMLWindow()->setView(m_view);
}

void MainMenuState::update()
{

}
