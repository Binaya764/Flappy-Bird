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
        void SpawnScoringPipe();
        void SpawnInvisiblePipe();

        const std::vector<sf::Sprite> &GetSprites() const;
        std::vector<sf::Sprite>&GetScoringSprites();

        private:

        GameDataRef _data;
        std::vector<sf::Sprite> pipeSprites;
        std::vector<sf::Sprite>ScoringPipes;

        int _landHeight;
        int _PipeSpawnYOffset;
    };
}