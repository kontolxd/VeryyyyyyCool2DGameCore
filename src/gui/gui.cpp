#include "gui.h"
GUI::GUI()
{
    m_assetManager = AssetManager::getAssetManager();
    m_x = 0;
    m_y = 0;
}

int GUI::getX()
{
    return m_x;
}

int GUI::getY()
{
    return m_y;
}
