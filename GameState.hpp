#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"
#include "HUD.hpp"

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
        HUD*  hud  = nullptr;

        Collision collision;

        int _gameState;
        int _score;

        sf::Clock clock;            // Used to time pipe spawning
        sf::SoundBuffer _hitSoundBuffer;
        sf::SoundBuffer _wingSoundBuffer;
        sf::SoundBuffer _pointSoundBuffer;

        sf::Sound _hitSound;
        sf::Sound _wingSound;
        sf::Sound _pointSound;
    };

}
