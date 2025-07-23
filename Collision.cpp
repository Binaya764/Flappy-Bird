#include "Collision.hpp"

namespace CE
{
    Collision::Collision()
    {
    }
         // Basic collision without padding
    bool Collision::CheckSpriteCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2)
    {
        sf::FloatRect rect1 = sprite1.getGlobalBounds();
        sf::FloatRect rect2 = sprite2.getGlobalBounds();

       if( rect1.intersects(rect2)) 
       {
        return true;
       }
       else
       {
        return false;
       }
    }
            
            //Shrinks the bounding box usind padding for more clean and tighter collision
     bool Collision::CheckSpriteCollision(const sf::Sprite& sprite1, float padding1,
                                     const sf::Sprite& sprite2, float padding2)
{
    sf::FloatRect rect1 = sprite1.getGlobalBounds();
    sf::FloatRect rect2 = sprite2.getGlobalBounds();

    rect1.left += padding1;
    rect1.top += padding1;
    rect1.width -= 10* padding1;
    rect1.height -= 10* padding1;

    rect2.left += padding2;
    rect2.top += padding2;
    rect2.width -= 10* padding2;
    rect2.height -= 10* padding2;

       if( rect1.intersects(rect2)) 
       {
        return true;
       }
       else
       {
        return false;
       }
    }
}
