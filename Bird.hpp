#pragma once
#include<SFML/GpuPreference.hpp>
#include"DEFINATIONS.hpp"
#include"Game.hpp"
#include<vector>

namespace CE
{
    class Bird  //Creating the bird class
    
    {
        public:
        Bird(GameDataRef data);

        void Animate(float dt);
        void Draw();
        void Update(float dt);
        void Tap();

        private:
        GameDataRef _data;
        std::vector<sf::Texture> _animationFrames;
        unsigned int _animationIterator;

        sf:: Clock _clock;
        sf::Clock _movementclock;
        sf::Sprite _birdSprite;

        int _birdState;

    };

}