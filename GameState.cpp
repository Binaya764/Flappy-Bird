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
        _data->assets.LoadTexture("Land",LAND_FILEPATH);
        _data->assets.LoadTexture("Bird frame 1",BIRD_FRAME_1_FILEPATH);
        _data->assets.LoadTexture("Bird frame 2",BIRD_FRAME_2_FILEPATH);
        _data->assets.LoadTexture("Bird frame 3",BIRD_FRAME_3_FILEPATH);
        _data->assets.LoadTexture("Bird frame 4",BIRD_FRAME_4_FILEPATH);

          pipe= new Pipe(_data); //create pipe object
          land= new Land(_data); //create land object
          bird= new Bird(_data); //create bird object

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
        if(_data->input.IsSpriteClicked( _background, sf::Mouse::Left, _data->window))
        {
            bird->Tap();
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
               
                pipe->RandowmisePipeOffset();
                clock.restart();     //Resets the time
        }
    
    land->MoveLand(dt);
    bird->Animate(dt);
    bird->Update(dt);
    }
    

    void GameState::Draw(float dt)
    {
        _data->window.clear();
        _data->window.draw(_background);
        pipe->DrawPipes();
        land->DrawLand();
        bird->Draw();



        _data->window.display();
    }
   
}


