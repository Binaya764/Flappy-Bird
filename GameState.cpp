#include <iostream>
#include "GameState.hpp"
#include "DEFINATIONS.hpp"
 

namespace CE {

    GameState::GameState(GameDataRef data) : _data(data) { }

    void GameState::Init()
    {
        
        _data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
         _data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
          _data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);

          pipe= new Pipe(_data); //create pipe object
        _background.setTexture(_data->assets.GetTexture("Game Background"));
    }

    void GameState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _data->window.close();

        }
        if(_data->input.IsSpriteClicked( _background, sf::Mouse::Left, _data->window)){
            
        }
            
               
    }

    void GameState::Update(float dt)
    {
        pipe->MovePipes(dt);

        if(clock.getElapsedTime().asSeconds()>PIPE_SPAWN_FREQUENCY)
        {
             //pipe->SpawnInvisiblePipe();
                pipe->SpawnBottomPipe();
                pipe->SpawnTopPipe();
                clock.restart();     //Resets the time
            }
        }
    

    void GameState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        pipe->DrawPipes();
        _data->window.display();
    }
   
}


