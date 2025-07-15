#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"

namespace CE {

    class GameState : public State {
    public:
        GameState(GameDataRef data);

        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Draw(float dt) override;

    private:
        GameDataRef _data;

        sf::Sprite _background;

        Pipe* pipe = nullptr;       // Initialize to nullptr for safety
        Land* land = nullptr;
        Bird* bird = nullptr;

        Collision collision;

        int _gameState;

        sf::Clock clock;            // Used to time pipe spawning
    };

}
