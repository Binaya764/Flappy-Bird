#include <iostream>
#include <stdexcept>  // For std::runtime_error
#include "AssetManager.hpp"

namespace CE {

    void AssetManager::LoadTexture(std::string name, std::string FileName)
    {
        sf::Texture tex;
        if (tex.loadFromFile(FileName)) {
            _textures[name] = std::move(tex);
        }
        else {
            std::cerr << "[AssetManager] ERROR: Failed to load texture from file: " << FileName << std::endl;
        }
    }

    sf::Texture& AssetManager::GetTexture(std::string name)
    {
        auto it = _textures.find(name);
        if (it == _textures.end()) {
            std::cerr << "[AssetManager] ERROR: Texture with key '" << name << "' not found." << std::endl;
            throw std::runtime_error("Texture not found: " + name);
        }

        return it->second;
    }

    void AssetManager::LoadFont(std::string name, std::string FileName)
    {
        sf::Font font;
        if (font.loadFromFile(FileName)) {
            _fonts[name] = std::move(font);
        }
        else {
            std::cerr << "[AssetManager] ERROR: Failed to load font from file: " << FileName << std::endl;
        }
    }

    sf::Font& AssetManager::GetFont(std::string name)
    {
        auto it = _fonts.find(name);
        if (it == _fonts.end()) {
            std::cerr << "[AssetManager] ERROR: Font with key '" << name << "' not found." << std::endl;
            throw std::runtime_error("Font not found: " + name);
        }

        return it->second;
    }

}
