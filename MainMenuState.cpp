
#include <sstream>
#include "MainMenuState.hpp"
#include "GameState.hPP"
#include "DEFINATIONS.hpp"
#include <iostream>

namespace CE {
    MainMenuState::MainMenuState(GameDataRef data) : _data(data)
    {
    }

    void MainMenuState::Init()
    {
        // Load texture with key "Main Menu Background"
        _data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);

        _data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);

        _data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

        
        _background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));

        _title.setTexture(this->_data->assets.GetTexture("Game Title"));

        _PlayButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        _title.setPosition((SCREEN_WIDTH /2) - (_title.getGlobalBounds().width/2), _title.getGlobalBounds().height/2);     //set position of title
        //Globalbouds is used to retrieve the bounding rectangle of a drawable object

        _PlayButton.setPosition((SCREEN_WIDTH /2) - (_PlayButton.getGlobalBounds().width/2),
        (SCREEN_HEIGHT /2) - (_PlayButton.getGlobalBounds().height/2) );
    }

    void MainMenuState::HandleInput()
    {
        sf::Event event;
        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _data->window.close();
            }
            if(_data->input.IsSpriteClicked( _PlayButton, sf::Mouse::Left, _data->window))
            {
                //Replaces mainmenu state with Game state
                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
        }
    }

    void MainMenuState::Update(float dt)
    {
       
    }

    void MainMenuState::Draw(float dt)
    {
        _data->window.clear();

        _data->window.draw(_background);
        _data->window.draw(_title);
        _data->window.draw(_PlayButton);

        _data->window.display();
    }
}
