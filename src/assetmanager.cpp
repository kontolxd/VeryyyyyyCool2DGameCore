#include "assetmanager.h"
AssetManager *AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
    if(sInstance == nullptr)
        sInstance = this;
}

AssetManager* AssetManager::getAssetManager()
{
    AssetManager *kostyl = new AssetManager();
    return sInstance;
}

sf::Texture& AssetManager::getTexture(std::string l_name)
{
    auto& texMap = sInstance->m_Textures;
    if(texMap.find(l_name) == texMap.end())
    {
        if(!texMap[l_name].loadFromFile(l_name))
        {
            //TODO ERROR
            printf("Error to load file: %s", l_name.c_str());
        }
    }
    return texMap[l_name];
}

sf::SoundBuffer& AssetManager::getSound(std::string l_name)
{
    auto& soundMap = sInstance->m_Sounds;
    if(soundMap.find(l_name) == soundMap.end())
    {
        if(!soundMap[l_name].loadFromFile(l_name))
        {
            //TODO ERROR
            printf("Error to load file: %s", l_name.c_str());
        }
    }
    return soundMap[l_name];
}

sf::Font& AssetManager::getFont(std::string l_name)
{
    l_name = nya::getWorkingDirectory()+"fonts/"+l_name;
    auto& fontMap = sInstance->m_Fonts;
    if(fontMap.find(l_name) == fontMap.end())
    {
        if(!fontMap[l_name].loadFromFile(l_name))
        {
            //TODO ERROR
            printf("Error to load file: %s", l_name.c_str());
        }
    }
    return fontMap[l_name];
}
