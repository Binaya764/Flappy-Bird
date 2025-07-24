// InputManager.hpp
#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <SFML/Graphics.hpp>

namespace CE {
    class InputManager {
    public:
        // Changed: now takes event to detect a single mouse button press
        static bool IsSpriteClicked(sf::Sprite object, sf::Event event, sf::RenderWindow &window);

        static sf::Vector2i GetMousePosition(sf::RenderWindow &window);

        static bool IsPlayKeyPressed(sf::Event event);
    };
}

#endif
