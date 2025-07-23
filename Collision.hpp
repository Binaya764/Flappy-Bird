#pragma once

#include <SFML/Graphics.hpp>

namespace CE
{
    class Collision
    {
    public:
        Collision();

        //uses rectangular box for collision detection
        bool CheckSpriteCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2); 

        //Scales down the rectangular box
        bool CheckSpriteCollision(const sf::Sprite& sprite1, float scale1, const sf::Sprite& sprite2, float scale2);
    };
}
