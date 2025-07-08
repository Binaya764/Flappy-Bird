#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include"Pipe.hpp"


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
        sf::Texture _backgroundtexture;
        sf::Sprite _background;
        Pipe *pipe;                     //pointer to a pipe object
        sf::Clock clock;                //To check the time passed

    };

}