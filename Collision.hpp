#pragma once

#include <SFML/Graphics.hpp>

namespace CE
{
    class Collision
    {
    public:
        Collision();

        // Pass by const reference for performance, fixed spelling
        bool CheckSpriteCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2);
    };
}
