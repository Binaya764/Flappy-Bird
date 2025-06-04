#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 600), "Flappy Bird Jump");
    window.setFramerateLimit(60);

    sf::CircleShape bird(20);
    bird.setFillColor(sf::Color::Yellow);
    bird.setPosition(100, 300);

    float velocity = 0;
    const float gravity = 0.5f;
    const float jumpStrength = -10.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Detect mouse click or spacebar
            if (event.type == sf::Event::MouseButtonPressed || 
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)) {
                velocity = jumpStrength;
            }
        }

        // Apply gravity and update position
        velocity += gravity;
        bird.move(0, velocity);

        // Prevent bird from going off the screen bottom
        if (bird.getPosition().y > 580) {
            bird.setPosition(bird.getPosition().x, 580);
            velocity = 0;
        }

        window.clear(sf::Color::Cyan);
        window.draw(bird);
        window.display();
    }

    return 0;
}
