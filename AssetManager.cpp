#include<iostream>
#include "AssetManager.hpp"

namespace CE {

    void AssetManager::LoadTexture(std::string name, std::string FileName)
    {
        sf::Texture tex;
        if (tex.loadFromFile(FileName)) {
            _textures[name] = std::move(tex);  // Move instead of copy
        }
        else {
            
            std::cerr << "Failed to load texture: " << FileName << std::endl;
        }
    }

    sf::Texture& AssetManager::GetTexture(std::string name)
    {
        return _textures.at(name);
    }

    void AssetManager::LoadFont(std::string name, std::string FileName)
    {
        sf::Font font;
        if (font.loadFromFile(FileName)) {
            _fonts[name] = std::move(font);  // Move instead of copy
        }
        else {
            std::cerr << "Failed to load font: " << FileName << std::endl;
        }
    }

    sf::Font& AssetManager::GetFont(std::string name)
    {
        return _fonts.at(name);
    }

}
