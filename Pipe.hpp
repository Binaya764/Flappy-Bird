#pragma once
#include<SFML/Graphics.hpp>
#include "Game.hpp"
#include<vector>
#include"DEFINATIONS.hpp"
namespace CE
{
    class Pipe
    {
        public:
        Pipe(GameDataRef data);
        void SpawnTopPipe();
        void SpawnBottomPipe();
        //void SpawnInvisiblePipe();
        void MovePipes(float dt);
        void DrawPipes();

        private:

        GameDataRef _data;
        std::vector<sf::Sprite> pipeSprites;
    };
}