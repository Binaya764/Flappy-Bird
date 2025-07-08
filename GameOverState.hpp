#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"


namespace CE {

    class GameOverState : public State {
    public:
        GameOverState(GameDataRef data);

        void Init() override;
        void HandleInput() override;
        void Update(float dt) override;
        void Draw(float dt) override;
        

    private:
        GameDataRef _data;
        sf::Texture _backgroundtexture;
        sf::Sprite _background;
    };

}