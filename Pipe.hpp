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
        void MovePipes(float dt);
        void DrawPipes();
        void RandowmisePipeOffset();

        private:

        GameDataRef _data;
        std::vector<sf::Sprite> pipeSprites;
        int _landHeight;
        int _PipeSpawnYOffset;
    };
}