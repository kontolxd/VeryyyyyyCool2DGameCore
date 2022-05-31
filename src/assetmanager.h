#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include"utilities.h"
class AssetManager
{
private:
    AssetManager();
    static AssetManager *sInstance;
    std::map<std::string, sf::Texture> m_Textures;
    std::map<std::string, sf::SoundBuffer> m_Sounds;
    std::map<std::string, sf::Font> m_Fonts;
public:
    static AssetManager* getAssetManager();
    static sf::Texture&     getTexture(std::string l_name);
    static sf::SoundBuffer& getSound(std::string l_name);
    static sf::Font&        getFont(std::string l_name);
    //TODO
    static sf::Shader&      getShader(std::string l_name);
};

#endif // ASSETMANAGER_H
