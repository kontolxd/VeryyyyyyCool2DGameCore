#include "mainmenu_state.h"

MainMenuState::MainMenuState()
{
    m_assetManager = AssetManager::getAssetManager();
    m_stateManager = StateManager::getStateManager();
    m_eventManager = EventManager::getEventManager();
    m_newButton = new TextBox();
    m_settingsButton = new TextBox();
    m_exitButton = new TextBox();

    m_newButton->setColor(sf::Color::Red);
    m_newButton->setSize(350,50);
    m_newButton->setFont("FreeMono.otf");
    m_newButton->setText("Generate new world");
    //m_newButton->setPosition(m_window->widht()/2-175, m_window->height()/2);
    //m_newButton->setAction(&MainMenuState::b_new, this);
    m_renderList.push_back(m_newButton);

    m_settingsButton->setColor(sf::Color::Red);
    m_settingsButton->setSize(150,50);
    m_settingsButton->setFont("FreeMono.otf");
    m_settingsButton->setText("Settings");
    //m_settingsButton->setPosition(m_window->widht()/2-75, m_window->height()/2+60);
    m_renderList.push_back(m_settingsButton);

    m_exitButton->setColor(sf::Color::Red);
    m_exitButton->setSize(100,50);
    m_exitButton->setFont("FreeMono.otf");
    m_exitButton->setText("Exit");
    //m_exitButton->setPosition(m_window->widht()/2-50, m_window->height()/2+120);
    m_exitButton->setAction(&MainMenuState::b_new, this);
    m_renderList.push_back(m_exitButton);

    m_eventManager->addCallback("clicked", &MainMenuState::clicked, this);
}

MainMenuState::~MainMenuState()
{
    delete m_newButton;
    delete m_settingsButton;
    delete m_exitButton;
}

void MainMenuState::active()
{
    m_window->getSFMLWindow()->setView(m_view);
    m_eventManager->addCallback("clicked", &MainMenuState::clicked, this);
}

void MainMenuState::update()
{
    m_newButton->setPosition(m_window->widht()/2-175, m_window->height()/2);
    m_settingsButton->setPosition(m_window->widht()/2-75, m_window->height()/2+60);
    m_exitButton->setPosition(m_window->widht()/2-50, m_window->height()/2+120);
}

void MainMenuState::clicked(EventDetails *l_details)
{
    int x1 = l_details->m_position.x;
    int y1 = l_details->m_position.y;
    int x2 = m_newButton->getX();
    int y2 = m_newButton->getY();
    int width = m_newButton->getWidth();
    int height = m_newButton->getHeight();
    if(x1 > x2 && y1 > y2 && x1 < x2 + width && y1 < y2 + height)
    {
        b_new();
    }
    x2 = m_settingsButton->getX();
    y2 = m_settingsButton->getY();
    width = m_settingsButton->getWidth();
    height = m_settingsButton->getHeight();
    if(x1 > x2 && y1 > y2 && x1 < x2 + width && y1 < y2 + height)
    {
        b_settings();
    }
    x2 = m_exitButton->getX();
    y2 = m_exitButton->getY();
    width = m_exitButton->getWidth();
    height = m_exitButton->getHeight();
    if(x1 > x2 && y1 > y2 && x1 < x2 + width && y1 < y2 + height)
    {
        b_exit();
    }
}

void MainMenuState::b_exit()
{

}

void MainMenuState::b_settings()
{

}

void MainMenuState::b_new()
{
    m_stateManager->activeState("game");
}
