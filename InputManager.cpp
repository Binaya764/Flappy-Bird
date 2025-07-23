#include "InputManager.hpp"

namespace CE {

    bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Event event, sf::RenderWindow &window)
    {
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            sf::IntRect buttonRect(object.getPosition().x, object.getPosition().y,
                                  object.getGlobalBounds().width, object.getGlobalBounds().height);

            if(buttonRect.contains(sf::Mouse::getPosition(window)))
            {
                return true;
            }
        }
        return false;
    }

    sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window)
    {
        return sf::Mouse::getPosition(window);
    }

    bool InputManager::IsPlayKeyPressed(sf::Event event)
    {
        return event.type == sf::Event::KeyPressed &&
               (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Up);
    }

}
