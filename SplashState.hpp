#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"


namespace CE {

    class SplashState : public State {
    public:
        SplashState(GameDataRef data);

        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Draw(float dt) override;
        

    private:
        GameDataRef _data;
        sf::Clock _clock;
        sf::Texture _backgroundtexture;
        sf::Sprite _background;
    };

}