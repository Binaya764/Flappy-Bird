#pragma once
#include<SFML/Graphics.hpp>
#include"DEFINATIONS.hpp"
#include "Game.hpp"

namespace CE
{
    class HUD
    {
        public:
        HUD(GameDataRef data);
        void Draw();
        void UpdateScore (int score);

        private:
        GameDataRef _data;
        sf::Text _scoreText;
    };
}
