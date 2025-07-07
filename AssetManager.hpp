#pragma once  /*preprocessor directive in C and C++ that ensures a header 
                file is included only once in a single compilation */
#include<map>
#include<SFML/Graphics.hpp>
namespace CE{
    class AssetManager{
        public:
        AssetManager(){}
        ~AssetManager(){}

        void LoadTexture( std::string name, std::string fileName);
        sf::Texture &GetTexture(std::string name);

        void LoadFont( std::string name,std::string fileName);
        sf::Font &GetFont(std::string name);

        private:
        std::map<std::string, sf::Texture>_textures;
        std::map<std::string, sf::Font>_fonts;
    };
}