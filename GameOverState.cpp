#include <iostream>
#include "GameOverState.hpp"
#include "DEFINATIONS.hpp"


namespace CE {

    GameOverState::GameOverState(GameDataRef data) : _data(data) { }

    void GameOverState::Init()
    {
       
        _data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        _background.setTexture(_data->assets.GetTexture("Game Over Background"));
    }

    void GameOverState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _data->window.close();
        }
    }

    void GameOverState::Update(float dt)
    {
        
    }

    void GameOverState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        _data->window.display();
    }
   
}


